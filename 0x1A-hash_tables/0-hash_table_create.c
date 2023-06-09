#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: the size, in number of nodes, to make the new hash table.
 *
 * Return: a pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned int ai = 0;
	hash_table_t *zt = malloc(sizeof(hash_table_t));

	if (zt == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	zt->size = size;
	zt->array = malloc(sizeof(hash_node_t *) * size);
	if (zt->array == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	for (; ai < size; ai++)
		zt->array[ai] = NULL;

	return (zt);
}
