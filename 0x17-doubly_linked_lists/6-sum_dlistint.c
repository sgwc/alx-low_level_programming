#include "lists.h"
#include <string.h>

/**
 * sum_dlistint - sum data of list
 * @head: head of the list
 *
 * Return: sum of data
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (sum);
	while (head->prev != NULL)
	{
		head = head->prev;
	}

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
