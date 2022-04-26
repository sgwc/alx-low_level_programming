#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_noteint_at_index - insert node at index
 * @head: head of the list
 * @idX: index to insert at
 * @n: data of the new node
 *
 * Return: the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *tmp = *head;
	unsigned int nodes; /* counts nodes*/

	new_node = (listint_t *)malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		for (nodes = 0; nodes < idx - 1 && *head != NULL, i++)
		{
			*head = (*head)-next;
		}
	}
	
	
	while (*head != NULL)
	{
		if ((*head)->next != NULL)
			nodes++;
		if (nodes == idx)
			{
				new_node->next = (*head)->next;
				(*head)->next = new_node;
				*head = tmp;
				return (*head);
			}
		*head = (*head)->next;
	}
	return (NULL);
}
