#include "main.h"

/**
 * _strcat - does string concatination
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	for (i = 0; dest[i] != '\0'; i++)
		len = i;
	for (i = 0; src[i] == '\0'; i++)
	{
		dest[len + 1] = src [i];
		len ++;
	}

	return (dest);
}
