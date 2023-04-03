#include "lists.h"
#include <stdio.h>

size_t listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * listint_len - counts number of nodes in listint_t list
 * @head: a pointer to the addressof a listint_t list
 * Return: 0 for success
 */
size_t listint_len(const listint_t *head)
{
	const listint_t *bag, *cab;
	size_t nod = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	bag = head->next;
	cab = (head->next)->next;

	while (cab)
	{
		if (bag == cab)
		{
			bag = head;
			while (bag != cab)
			{
				nod++;
				bag = bag->next;
				cab = cab->next;
			}
			bag = bag->next;
			while (bag != cab)
			{
				nod++;
				bag = bag->next;
			}
			return (nod);
		}
		bag = bag->next;
		cab = (cab->next)->next;
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: a pointer to the address of the listint_t list
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t node, i = 0;

	node = listint_len(head);

	if (node == 0)
	{
		for (; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (i = 0; i < node; i++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node);
}
