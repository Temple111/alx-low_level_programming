#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int ai = 0;
	hash_node_t *nd;

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
