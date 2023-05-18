#include "lists.h"

/**
 * free_dlistint -  frees a dlistint_t list.
 * @head: pointer to address of first node
 * Return: 0 for success
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *cp;

	while (head != NULL)
	{
		cp = head;
		head = head->next;
		free(cp);
	}
}
