#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t list
 * @head: a pointer to the head address of the listint_t list
 * Return: 0 if list is empty or head nodes data
 */
int pop_listint(listint_t **head)
{
	listint_t *cm;
	int a;

	if (*head == NULL)
		return (0);

	cm = *head;
	a = (*head)->n;
	*head = (*head)->next;

	free(cm);

	return (a);
}
