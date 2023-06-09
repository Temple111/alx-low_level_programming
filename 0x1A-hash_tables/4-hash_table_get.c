#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: a pointer to the hash table array.
 * @key: the key, a string that cannot be empty.
 *
 * Return: the value associated with the key, or NULL if key can't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *nd;

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
