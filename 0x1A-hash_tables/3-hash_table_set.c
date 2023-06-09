#include "hash_tables.h"

/**
 * set_pair - mallocs a key/value pair to the hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: pointer to the new node.
 */
hash_node_t *set_pair(const char *key, const char *value)
{
	hash_node_t *nd = malloc(sizeof(hash_node_t));

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
 * set_pair_only - (no collision) set key:value pair to first array element
 * @ht: pointer to the hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 * @index: the key's index.
 *
 * Return: the node, or NULL if failed.
 */
int set_pair_only(hash_table_t *ht, const char *key,
		  const char *value, unsigned long int index)
{
	hash_node_t *nd = set_pair(key, value);

	if (nd == NULL)
		return (0);
	nd->next = NULL;
	ht->array[index] = nd;
	return (1);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: a pointer to the hash table array.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: 1 on success, 0 on error.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *nd;

	if (key == NULL || ht == NULL)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	nd = ht->array[idx];
	if (nd == NULL)
		return (set_pair_only(ht, key, value, idx));
	while (nd != NULL)
	{
		if (strcmp(nd->key, key) == 0)
		{
			if (strcmp(nd->value, value) == 0)
				return (1);
			free(nd->value);
			nd->value = malloc(strlen(value) + 1);
			if (nd->value == NULL)
				return (0);
			strcpy(nd->value, value);
			return (1);
		}
		nd = nd->next;
	}
	if (nd == NULL)
	{
		nd = set_pair(key, value);
		if (nd == NULL)
			return (0);
		nd->next = ht->array[idx];
		ht->array[idx] = nd;
		return (1);
	}
	return (0);
}
