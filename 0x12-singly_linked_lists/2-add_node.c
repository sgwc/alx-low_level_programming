#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add a new node at the beginning of a list_t
 * @head: head of list
 * @str: string to be assign
 *
 * Return: pointer to this new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t len;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	for (len = 0; str[len]; len++)
		;

	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
