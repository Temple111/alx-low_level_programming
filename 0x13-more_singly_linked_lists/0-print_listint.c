#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints elements of a listint_t list
 * @h: a pointer to the head of the list_t list
 * Return: 0 for success
 */
size_t print_listint(const listint_t *h)
{
	size_t nd = 0;

	while (h)
	{
		nd++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (nd);
}
