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
	
	size = strlen(str);

	if (size != 0)
	{
		s = malloc((size + 1) * sizeof(char));
	}
	else
	{
		return (NULL);
	}
	s = strcpy(s,str);
	return (s);
}
