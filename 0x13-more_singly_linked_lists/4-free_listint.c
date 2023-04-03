#include"lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: a pointer to listint_t list to be freed
 */

void free_listint(listint_t *head)
{
	listint_t *n;

	while (head)
	{
		n = head->next;
		free(head);
		head = n;
	}
}
