#include "hash_tables.h"
/**
 * hash_table_create - Function that creates a hash table
 * @size: is the size of the array
 * Return: a pointer to the newly created hash table or return NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int counter;
	hash_table_t *dict;

	dict = malloc(sizeof(hash_table_t));

	if (dict == NULL)
		return (NULL);

	dict->size = size;
	dict->array = malloc(sizeof(hash_node_t *) * size);

	if (dict->array == NULL)
	{
		return(NULL);
	}
	for (counter = 0; counter < size; counter++)
	{
		dict->array[counter] = NULL;
	}
	return (dict);
}
