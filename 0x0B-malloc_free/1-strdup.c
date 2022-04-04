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

	if (str != NULL)
	{
		size = strlen(str) + 1;
		s = malloc((size) * sizeof(char));
	}
	else
		return (NULL);
	if (s != NULL)
	{
		s = strcpy(s, str);
		return (s);
	}
	else 
		return (NULL);
}
