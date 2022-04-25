#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint - free space used by list
 * @head: head of the list
 *
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	next = NULL;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	
}
