#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: number of array slots to make the table.
 *
 * Return: pointer to the hash table created, or NULL if malloc failed.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned int ai = 0;
	shash_table_t *zt = malloc(sizeof(shash_table_t));

	if (zt == NULL)
		return (NULL);
	zt->size = size;
	zt->shead = NULL;
	zt->stail = NULL;
	zt->array = malloc(sizeof(shash_node_t *) * size);
	if (zt->array == NULL)
	{
		free(zt);
		return (NULL);
	}
	for (; ai < size; ai++)
		zt->array[ai] = NULL;
	return (zt);
}

/**
 * set_spair - mallocs a key/value pair to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: pointer to the new node.
 */
shash_node_t *set_spair(const char *key, const char *value)
{
	shash_node_t *nd = malloc(sizeof(shash_node_t));

	if (nd == NULL)
		return (NULL);
	nd->key = malloc(strlen(key) + 1);
	if (nd->key == NULL)
		return (NULL);
	nd->value = malloc(strlen(value) + 1);
	if (nd->value == NULL)
		return (NULL);
	strcpy(nd->key, key);
	strcpy(nd->value, value);
	return (nd);
}

/**
 * set_spair_only - (no collision) set key:value pair to first array element
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 * @index: the key's index.
 *
 * Return: the node, or NULL if failed.
 */
shash_node_t *set_spair_only(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *nd = set_spair(key, value);

	if (nd == NULL)
		return (NULL);
	nd->next = NULL;
	ht->array[index] = nd;
	return (nd);
}

/**
 * update_value - updates the value of a given node.
 * @node: pointer to the node.
 * @value: string to put at the node.
 *
 * Return: 1 on success, 0 on fail.
 */
int update_value(shash_node_t *node, const char *value)
{
	if (strcmp(node->value, value) == 0)
		return (1);
	free(node->value);
	node->value = malloc(strlen(value) + 1);
	if (node->value == NULL)
		return (0);
	strcpy(node->value, value);
	return (1);
}

/**
 * set_spair_front - sets key:value pair node to front of given index's list.
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 * @index: the key's index.
 *
 * Return: the new node, or NULL if failed.
 */
shash_node_t *set_spair_front(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *nd = set_spair(key, value);

	if (nd == NULL)
		return (0);
	nd->next = ht->array[index];
	ht->array[index] = nd;
	return (nd);
}

/**
 * slist_set_first - sets the first addition to the sorted list.
 * @ht: pointer to the sorted hash table.
 * @node: pointer to the first node on the table.
 *
 * Return: Always 1.
 */

int slist_set_first(shash_table_t *ht, shash_node_t *node)
{
	node->sprev = NULL;
	node->snext = NULL;
	ht->shead = node;
	ht->stail = node;
	return (1);
}

/**
 * slist_set - sets a new node before the given old node.
 * @ht: pointer to the sorted hash table.
 * @old_node: the node to place the new node in front of.
 * @node: the new node to place in front of the old one.
 *
 * Return: Always 1 (success).
 */
int slist_set(shash_table_t *ht, shash_node_t *old_node, shash_node_t *node)
{
	if (old_node->sprev == NULL)
		ht->shead = node;
	node->snext = old_node;
	node->sprev = old_node->sprev;
	old_node->sprev = node;
	if (node->sprev != NULL)
		node->sprev->snext = node;
	return (1);
}

/**
 * slist_set_end - sets a node at the end of the sorted list
 * @ht: pointer to the sorted hash table.
 * @node: the node to place at the end.
 *
 * Return: Always 1 (success).
 */
int slist_set_end(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *old_nd = ht->stail;

	ht->stail = node;
	node->snext = NULL;
	node->sprev = old_nd;
	old_nd->snext = node;
	return (1);
}

/**
 * shash_table_set - adds or updates an element to the sorted hash table.
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: 1 on success, 0 on error.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *nd, *cur_nd;

	if (key == NULL || ht == NULL)
		return (0);
/* set the item in the table */
	idx = key_index((unsigned char *)key, ht->size);
	nd = ht->array[idx];
	if (nd == NULL)
		nd = set_spair_only(ht, key, value, idx);
	else
	{
		while (nd != NULL)
		{
			if (strcmp(nd->key, key) == 0)
				return (update_value(nd, value));
			nd = nd->next;
		}
		nd = set_spair_front(ht, key, value, idx);
	}
	if (nd == NULL)
		return (0);
/* arrange the item in the sorted linked list */
	if (ht->shead == NULL)
		return (slist_set_first(ht, nd));
	cur_nd = ht->shead;
	while (cur_nd != NULL)
	{
		if (strcmp(cur_nd->key, nd->key) >= 0)
			return (slist_set(ht, cur_nd, nd));
		cur_nd = cur_nd->snext;
	}
	return (slist_set_end(ht, nd));
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: a pointer to the sorted hash table array.
 * @key: the key, a string that cannot be empty.
 *
 * Return: the value associated with the key, or NULL if key can't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *nd;

	if (ht == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx] == NULL)
		return (NULL);
	if (strcmp(ht->array[idx]->key, key) == 0)
		return (ht->array[idx]->value);
	nd = ht->array[idx];
	while (nd != NULL)
	{
		if (strcmp(nd->key, key) == 0)
			return (nd->value);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints key/value pairs in sorted hash table order.
 * @ht: the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int count_1 = 0;
	shash_node_t *nd = ht->shead;

	if (ht == NULL)
		return;
	printf("{");
	while (nd != NULL)
	{
		if (count_1 > 0)
			printf(", ");
		printf("'%s': '%s'", nd->key, nd->value);
		nd = nd->snext;
		count_1++;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted key/value pairs in reverse.
 * @ht: the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int count_1 = 0;
	shash_node_t *nd = ht->stail;

	if (ht == NULL)
		return;
	printf("{");
	while (nd != NULL)
	{
		if (count_1 > 0)
			printf(", ");
		printf("'%s': '%s'", nd->key, nd->value);
		nd = nd->sprev;
		count_1++;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int ai = 0;
	shash_node_t *nd;

	while (ai < ht->size)
	{
		while (ht->array[ai] != NULL)
		{
			nd = ht->array[ai]->next;
			free(ht->array[ai]->key);
			free(ht->array[ai]->value);
			free(ht->array[ai]);
			ht->array[ai] = nd;
		}
		ai++;
	}
	free(ht->array);
	free(ht);
}
