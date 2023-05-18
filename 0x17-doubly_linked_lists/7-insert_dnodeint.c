#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @idx: index at which node is to be inserted
 * @n: number of lists present
 * @h: pointer to the address of first node
 * Return:0 for success
 */


dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *nw_nd = NULL;
dlistint_t *cp = *h;
unsigned int a = 0;

if (h == NULL)
return (NULL);

nw_nd = malloc(sizeof(dlistint_t));
if (nw_nd == NULL)
return (NULL);

nw_nd->n = n;

if (idx == 0)
{
nw_nd->next = *h;
nw_nd->prev = NULL;
if (*h != NULL)
(*h)->prev = nw_nd;
*h = nw_nd;
return (nw_nd);
}

while (cp != NULL && a < idx - 1)
{
cp = cp->next;
a++;
}

if (cp == NULL)
return (NULL);

nw_nd->next = cp->next;
nw_nd->prev = cp;
if (cp->next != NULL)
cp->next->prev = nw_nd;
cp->next = nw_nd;

return (nw_nd);
}

