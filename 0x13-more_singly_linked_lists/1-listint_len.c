#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns the number of elements
 * @h: a pointer to the head of the listint_t list
 * Return: 0 for success
 */

size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
