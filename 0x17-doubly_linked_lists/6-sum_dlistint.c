#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of dlistint_t linked list
 * @head: pointer to the address of first node
 * Return: 0 for success
 */


int sum_dlistint(dlistint_t *head)
{
int add = 0;

dlistint_t *a;

for (a = head; a != NULL; a = a->next)
{
add += a->n;
}
return (add);
}
