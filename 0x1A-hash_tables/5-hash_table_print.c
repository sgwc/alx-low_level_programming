#include "hash_tables.h"
/**
 * hash_table_print - function to print a hash table in C
 * @ht: hash table to be printed
 * Return: printed elements of hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	unsigned int count = 0;
	hash_node_t *aux;

	if (!ht)
		return;
	printf("{");
	while (idx < ht->size)
	{
		aux = ht->array[idx];
		while (aux != NULL)
		{
			if (count == 1)
				printf(", ");
			printf("'%s': '%s'", aux->key, aux->value);
			count = 1;
			aux = aux->next;
		}
		idx++;
	}
	printf("}\n");
}
