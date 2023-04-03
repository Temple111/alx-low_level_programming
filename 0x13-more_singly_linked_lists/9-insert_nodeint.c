#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given positon
 * @idx: the index of the list where the new nide should be added,
 *       starting from 0
 * @head: a pointer to the address of the listint_t list
 * @n: the integer to contain the new node
 * Return: the address of the new node when successful or NULL if it fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *ab = *head;
	unsigned int nod;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	if (idx == 0)
	{
		newnode->next = ab;
		*head = newnode;
		return (newnode);
	}
	for (nod = 0; nod < (idx - 1); nod++)
	{
		if (ab == NULL || ab->next == NULL)
			return (NULL);
		ab = ab->next;
	}

	newnode->next = ab->next;
	ab->next = newnode;

	return (newnode);
}
