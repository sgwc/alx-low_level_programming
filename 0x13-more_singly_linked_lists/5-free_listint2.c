#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint2 - free list
 * @head: head of the list
 *
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *next;

	next = NULL;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	*head = NULL;
}
