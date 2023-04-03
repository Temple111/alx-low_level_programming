#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: a pointer to the addresss of a listint_t list
 * Return: 0 for success
 */

void free_listint2(listint_t **head)
{
	listint_t *cm;

	if (head == NULL)
		return;

	while (*head)
	{
		cm = (*head)->next;
		free(*head);
		*head = cm;
	}
	head = NULL;
}
