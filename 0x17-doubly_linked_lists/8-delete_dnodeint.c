#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of dlistint_t list.
 * @head: pointer to the address of first node
 * @index: index where the node is to be deleted
 * Return: 0 for success
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *curr_nd = *head;
dlistint_t *cp = NULL;
unsigned int a = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
cp = (*head)->next;
free(*head);
*head = cp;
if (*head != NULL)
(*head)->prev = NULL;
return (1);
}

for (a = 0; curr_nd != NULL && a < index - 1; a++)
curr_nd = curr_nd->next;

if (curr_nd == NULL || curr_nd->next == NULL)
return (-1);

cp = curr_nd->next->next;
free(curr_nd->next);
curr_nd->next = cp;
if (curr_nd->next != NULL)
curr_nd->next->prev = curr_nd;

return (1);
}
