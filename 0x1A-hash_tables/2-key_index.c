#include "hash_tables.h"
/**
 *key_index - function that show a key index
 *@key: is a key
 *@size: is size of array
 *Return: index at which the key pair should be stored array of the hash table
 */


unsigned long int key_index(const unsigned char *key, unsigned long int size)
{

	unsigned long int index;

	index = hash_djb2(key) % size;

	return (index);

}
