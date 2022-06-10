#include "lists.h"
#include <string.h>

/**
 * add_dnodeint_end - adds new node at the end
 * @head: head of the list
 * @n: data value of the new node
 *
 * Return: head of the updated list
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	h = *head;

	if (h != NULL)
	{
		while(h->next != NULL)
			h = h->next;
	}

	new->prev = h;
	if (h != NULL)
		h->next = new;

	*head = new;

	return (new);
}
