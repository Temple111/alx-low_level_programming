#include "lists.h"

/**
 * dlistint_len - This the number of elements in a linked dlistint_t list.
 * @h: address to the first node
 * Return: 0 for success
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t ele_count = 0;
	const dlistint_t *curr_nd = h;

	while (curr_nd != NULL)
	{
		ele_count++;
		curr_nd = curr_nd->next;
	}
	return (ele_count);
}
