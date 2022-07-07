#include "hash_tables.h"

/**
 * hash_table_get - get value using key
 * @ht: hast table
 * @key: used to get the value
 *
 * Return: the value or NULL if not key like that
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx = 0;
	hash_node_t *c = NULL;

	if (ht == NULL || key == NULL)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	c = ht->array[idx];
	if (c == NULL)
	{
		return (NULL);
	}
	while (c != NULL)
	{
		if (!strcmp(c->key, key))
		{
			return (c->value);
		}
		c = c->next;
	}
	return (NULL);
}
