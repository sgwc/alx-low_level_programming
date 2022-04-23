#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - lengeth of the linked list
 * @h: singly_liknked list input
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t nodes;

	nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
