#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatinat s2 on to s1
 * @s1: first string
 * @s2: the stirng to be appended on to s1
 *
 * Return: newely allowcated memory
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i, j, size;

	if (s1 == NULL && s2 == NULL)
	{
		s1 = "";
		s2 = "";
	}
	else if (s1 == NULL)
	{
		s1 = "";
	}
	else if (s2 == NULL)
	{
		s2 = "";
	}

	size = strlen(s1) + strlen(s2) + 1;

	s = (char *)malloc(size * sizeof(char));

	if (s == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(s1 + i) != '\0'; i++)
		*(s + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(s + i) = *(s2 + j);
		i++;
	}
	*(s + i) = '\0';

	return (s);
}
