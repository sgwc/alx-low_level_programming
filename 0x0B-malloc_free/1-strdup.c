#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * _strdup - copy string provide into the new memory block
 * @str: size of the memory to be allocated
 *
 * Return: pointer to newly created array
 *
 */

char *_strdup(char *str)
{
	int size;
	char *s;
	
	size = strlen(str) + 1;

	if (size != 0)
	{
		s = malloc((size) * sizeof(char));
	}
	else if (str == NULL)
	{
		return (NULL);
	}

	s = strcpy(s, str);
	return (s);
}
