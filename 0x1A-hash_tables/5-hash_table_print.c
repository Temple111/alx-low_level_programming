#include "hash_tables.h"

/**
 * hash_table_print - prints key/value pairs in hash table array order.
 * @ht: the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int ai, count_1 = 0;
	hash_node_t *nd;

	if (ht == NULL)
		return;
	printf("{");
	for (ai = 0; ai < ht->size; ai++)
	{
		if (ht->array[ai] != NULL)
		{
			nd = ht->array[ai];
			while (nd != NULL)
			{
				if (count_1 > 0)
					printf(", ");
				printf("'%s': '%s'", nd->key, nd->value);
				nd = nd->next;
				count_1++;
			}
		}
	}
	printf("}\n");
}
