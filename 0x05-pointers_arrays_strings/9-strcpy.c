#include "main.h"

/**
 * _strcpy - copy the string pointed by scr
 * @dest: the pointer pointing to the
 * @src: the source string to be copy
 * Return: a pointer
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
