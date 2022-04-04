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

	if (size != 0)
	{
		s = malloc(size * sizeof(char));
	}
	else
	{
		return (NULL);
	}

	if (s == NULL)
		return (NULL);

	else
		return (s);
}
