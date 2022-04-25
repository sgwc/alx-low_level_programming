#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * listint_len - finds the length of the list
 * @h: given list
 *
 * Return: the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	unsigned int len;

	len = 0;
	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}
