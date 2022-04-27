#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_nodeint_at_index - get node
 * @head: head of the list
 * @index: indext of the node
 *
 * Return: node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	
	listint_t *temp = head;
	
	while (temp && count < index)
	{
		temp = temp->next;
		count++;
	}
	return (temp ? temp : NULL);
}
