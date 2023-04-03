#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: a pointer to the address of listint_t list
 * Return: address of the node where the loop starts or NULL if
 *          there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *bag, *cab;

	if (head == NULL || head->next == NULL)
		return (NULL);

	bag = head->next;
	cab = (head->next)->next;

	while (cab)
	{
		if (bag == cab)
		{
			bag = head;
			while (bag != cab)
			{
				bag = bag->next;
				cab = cab->next;
			}
			return (bag);
		}

		bag = bag->next;
		cab = (cab->next)->next;
	}
	return (NULL);
}

