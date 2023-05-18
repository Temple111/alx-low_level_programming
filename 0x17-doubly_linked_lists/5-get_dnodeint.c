#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to address of first node
 * @index: the index to return the nth node from
 * Return: 0 for success
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int a = 0;

dlistint_t *cp = head;

while (cp != NULL && a < index)
{
cp = cp->next;
a++;
}
if (a == index)
return (cp);
return (NULL);
}
