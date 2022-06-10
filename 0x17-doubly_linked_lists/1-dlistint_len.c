#include "lists.h"
#include <string.h>

/**
 * dlistint_len - find the number of nodes
 * @h: head of the linked list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	if (h == NULL)
		return (nodes);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
