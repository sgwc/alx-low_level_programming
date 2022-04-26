#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * delete_nodeint_at_intdex - insert node at index
 * @head: head of the list
 * @indeX: index to insert at
 *
 * Return: 1 on success -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int nodes; /* counts nodes*/
	listint_t *prev;
	listint_t *next;

	prev = *head;
	if (index != 0)
	{
		for (nodes = 0; nodes < index - 1 && prev != NULL; nodes++)
		{
			prev = prev->next;
		}
	}
	if (prev == NULL || (prev->next == NULL && index != 0))
	{
		return (-1);
	}

	next = prev->next;

	if (index != 0)
	{
		prev->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*head = next;
	}
	return (1);
}
