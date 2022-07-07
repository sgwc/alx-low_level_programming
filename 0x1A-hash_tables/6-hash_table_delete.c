#include "hash_tables.h"
/**
 * hash_table_delete - Hash function to delete a table
 * @ht: table to be deleted
 * Return: always successful
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned int idx = 0;
	hash_node_t *aux;
	hash_node_t *c = NULL;

	for (idx = 0; idx < ht->size; idx++)
	{
		c = ht->array[idx];
		while (c != NULL)
		{
			aux = c->next;
			free(c->value);
			free(c->key);
			free(c);
			c = aux;
		}
	}
	free(ht->array);
	free(ht);
}
