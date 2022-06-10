#include "lists.h"
#include <string.h>

/**
 * print_dlistint - prints node data of the list
 * @h: head of the linked list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;
	const dlistint_t *temp;
	
	if (h == NULL)
	{
		return(nodes);
	}
	else
	{	
		temp = h;
		while(temp != NULL)
		{
			nodes += 1;
			printf("%d\n", temp->n);
			temp = temp->next;
		}
		return(nodes);
	}
}
