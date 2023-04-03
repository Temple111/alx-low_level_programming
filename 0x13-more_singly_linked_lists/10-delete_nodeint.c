#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t
 *                           linked list
 * @index: is the index of the node that should be deleted, starting at 0
 * @head: a pointer to the the address of the listint_t list
 * Return: 1 if successful or -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *cm, *ab = *head;
	unsigned int nod;

	if (ab == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(ab);
		return (1);
	}

	for (nod = 0; nod < (index - 1); nod++)
	{
		if (ab->next == NULL)
			return (-1);
		ab = ab->next;
	}

	cm = ab->next;
	ab->next = cm->next;
	free(cm);
	return (1);
}
