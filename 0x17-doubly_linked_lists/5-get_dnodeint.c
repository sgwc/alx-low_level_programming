#include "lists.h"
#include <string.h>

/**
 * get_dnodeint_at_index - get node at index
 * @head: head of the list
 * @index: index of the node
 *
 * Return: data of the node at index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp = head;
	unsigned int node_count;

	if (head == NULL)
	{
		node_count = 0;
		return (NULL);
	}
	else
		node_count = 1;

	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	
	while (tmp != NULL)
	{
		if ((node_count - 1) == index)
			break;
		tmp = tmp->next;
		node_count++;
	}
	return (tmp);
}
