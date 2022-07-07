#include "hash_tables.h"
/**
 *hash_table_set - function that adds an element to the hash table.
 *@ht:the hash table you want to add or update the key
 *@key: is key
 *@value:is the value associated with the key
 *Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *n;
	char *c;
	unsigned long int index, i;

	if (ht == NULL || *key == '\0' || key == NULL || value == NULL)
	{
		return (0);
	}

	c = strdup(value);
	if (c == NULL)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = c;
			return (1);
		}
	}
	n = malloc(sizeof(hash_node_t));
	if (n == NULL)
	{
		free(c);
		return (0);
	}
	n->key = strdup(key);
	if (n->key == NULL)
	{
		free(n);
		return (0);
	}
	n->value = c;
	n->next = ht->array[index];
	ht->array[index] = n;
	return (1);
}
