#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint - prints elements of the list
 * @h: singly list given
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	unsigned int nodes;

	nodes = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	}
	return (nodes);
}
