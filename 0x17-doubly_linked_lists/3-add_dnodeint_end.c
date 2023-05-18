#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to address of first node
 * @n: number of node to add
 * Return:0 for success
 */


dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw_nd = malloc(sizeof(dlistint_t));
	dlistint_t *end = *head;

	if (!nw_nd)
		return (NULL);

	nw_nd->n = n;
	nw_nd->next = NULL;

	if (!*head)
	{
		nw_nd->prev = NULL;
		*head = nw_nd;
		return (nw_nd);
	}
	while (end->next)
		end = end->next;

	end->next = nw_nd;
	nw_nd->prev = end;

	return (nw_nd);
}
