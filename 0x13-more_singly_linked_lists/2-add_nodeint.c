#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint - addes a node at the biginnig
 * @head: head of the list
 * @n: data of the new node
 *
 * Return: the list
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
