#include "lists.h"
#include <string.h>

/**
 * print_dlistint - prints node data of the list
 * @h: head of the linked list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;
	
	if (h == NULL)
	{
		return (nodes);
	}
	while (h->prev != NULL)
		h = h->prev;
	else
	{	
		while (h != NULL)
		{
			nodes++;
			printf("%d\n", h->n);
			h = h->next;
		}
		return (nodes);
	}
}
