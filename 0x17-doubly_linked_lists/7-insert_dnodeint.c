#include "lists.h"
#include <string.h>

/**
 * insert_dnodeint_at_index - insert node at index idx
 * @head: head of the list
 * @idx: index of the node
 *
 * Return: updated list
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int idx, int n)
{
	unsigned int node_count;
      	dlistint_t *tmp = *head;
      	dlistint_t *new = malloc(sizeof(dlistint_t*));
      
	if (new == NULL)
      	{
		return(NULL);
      	}
	if (head == NULL)
	{
		node_count = 0;
		return (NULL);
	}
	else
		node_count = 1;
      
	new->n = n;
      	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}

	while (tmp != NULL)
	{
		if ((node_count ) == idx)
			break;
		tmp = tmp->next;
		node_count++;
	}
      	if (tmp->next != NULL)
      	{
		tmp->next = new;
	    	new->prev = tmp;
	    	new->next = tmp->next->next;
		tmp = tmp->next->next;
		tmp->prev = new;
      	}
      	else
     	{
	    	tmp->next = new;
	    	new->prev = tmp;
	    	new->next = NULL;
      	}
      	
	tmp = new;
	return (tmp);
}
