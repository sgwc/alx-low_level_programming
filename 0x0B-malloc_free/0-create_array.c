#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * create_array - creates an array of chars
 * @size: size of the memory to be allocated
 * @c: character to initalize the array
 *
 * Return: pointer to newly created array
 *
 */

char *create_array(unsigned int size, char c)
{
	char *s;

	s = malloc(size * sizeof(char));
	if (s == NULL)
	{
		printf("failed to allocate memory\n");
		return (NULL);
	}
	s = memset(s, c, size);
	return (s);
}
