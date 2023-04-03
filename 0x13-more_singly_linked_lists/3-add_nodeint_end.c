#include "lists.h"

/**
 * add_nodeint_end - adds new node at the end of a listint_t list
 * @head: a pointer to the address of the head of a listint_t list
 * @n: the integer for new node
 * Return: NULL if funtion fails or the address of the new element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *end;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
		*head = newnode;
	else
	{
		end = *head;
		while (end->next != NULL)
			end = end->next;
		end->next = newnode;
	}
	return (*head);
}
