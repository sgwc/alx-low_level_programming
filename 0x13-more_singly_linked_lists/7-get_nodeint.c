#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_node_at_index - get node
 * @head: head of the list
 * @index: indext of the node
 *
 * Return: node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);
	while (head != NULL)
	{
		++count;
		if (count == index)
		{
			return (head->next);
		}
		head = head->next;
	}
	return (NULL);
}
