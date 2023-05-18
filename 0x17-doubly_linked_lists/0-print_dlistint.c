#include "lists.h"

/**
 * print_dlistint - prints the elements of a distinct lists
 * @h: pointer to the head address of list
 * Return: 0 for success
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t all_ele = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		all_ele++;
	}
	return (all_ele);
}
