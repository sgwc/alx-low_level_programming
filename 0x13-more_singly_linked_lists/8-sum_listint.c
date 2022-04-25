#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sum_listint - sum of all the data of linked list
 * @head: head of the list
 *
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
