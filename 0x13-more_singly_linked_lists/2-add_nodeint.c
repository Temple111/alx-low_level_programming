#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of listint_t list
 * @head: a pointer to the address of the head
 * @n: the integer for the new node
 * Return: NULL if function fails or te address of the new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;

	*head = newnode;

	return (newnode);
}
