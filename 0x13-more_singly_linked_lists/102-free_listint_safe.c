#include "lists.h"
#include <stdio.h>

size_t listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * listint_count - counts number of nodes in listint_t list
 * @head: a pointer to the addressof a listint_t list
 * Return: 0 for success
 */
size_t listint_count(listint_t *head)
{
	listint_t *bag, *cab;
	size_t nod = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	bag = head->next;
	cab = (head->next)->next;

	while (cab)
	{
		if (bag == cab)
		{
			bag = head;
			while (bag != cab)
			{
				nod++;
				bag = bag->next;
				cab = cab->next;
			}
			bag = bag->next;
			while (bag != cab)
			{
				nod++;
				bag = bag->next;
			}
			return (nod);
		}
		bag = bag->next;
		cab = (cab->next)->next;
	}
	return (0);
}

/**
 * free_listint_safe - frees a listint_t linked list and set the head to NULL
 * @h: a pointer to the address of the listint_t list
 * Return: the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *cm;
	size_t node, i;

	node = listint_count(*h);
	if (node == 0)
	{
		for (; h != NULL && *h != NULL; node++)
		{
			cm = (*h)->next;
			free(*h);
			*h = cm;
		}
	}
	else
	{
		for (i = 0; i < node; i++)
		{
			cm = (*h)->next;
			free(*h);
			*h = cm;
		}
		*h = NULL;
	}
	h = NULL;
	return (node);
}

