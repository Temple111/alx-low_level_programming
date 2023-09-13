#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 *
 * @list: input list
 * @value: value to search in
 * Return: index of the number
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *u;

	if (list == NULL)
		return (NULL);

	u = list;

	do {
		list = u;
		u = u->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)u->index, u->n);
	} while (u->express && u->n < value);

	if (u->express == NULL)
	{
		list = u;
		while (u->next)
			u = u->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)u->index);

	while (list != u->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
