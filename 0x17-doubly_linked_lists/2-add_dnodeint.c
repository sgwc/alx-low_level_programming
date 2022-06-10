#include "lists.h"
#include <string.h>

/**
 * add_dnodeint - adds new node at the head
 * @head: head of the list
 * @n: data value of the new node
 *
 * Return: head of the updated list
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);
	
	new->n = n;
	new->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while(h->prev != NULL)
			h = h->prev;
	}
	
	new->next = h;

	if (h != NULL)
		h->prev = new;
	
	*head = new;

	return (new);
}
