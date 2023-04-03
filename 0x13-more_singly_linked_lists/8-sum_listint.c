#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data (n) of a listint_t
 *               linked list
 * @head: a pointer to the head of the list
 * Return: 0 if lit is empty or the calculated sum
 */

int sum_listint(listint_t *head)
{
	int add = 0;

	while (head)
	{
		add = add + head->n;
		head = head->next;
	}

	return (add);
}
