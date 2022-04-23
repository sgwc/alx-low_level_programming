#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - prints data of the linked list
 * @h: singly_liknked list input
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t nodes;

	nodes = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		nodes++;
	}
	return (nodes);
}
