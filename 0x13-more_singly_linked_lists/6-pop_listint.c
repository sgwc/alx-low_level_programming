#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * @head: head of list
 *
 * Return: data of the head
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *next = *head;

	if (*head == NULL)
		return (0);
	else
	{
		data = (*head)->n;
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	return (data);
}
