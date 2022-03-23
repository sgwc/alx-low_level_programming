#include "main.h"

/**
 * _strncat - does string concatination
 * @dest: destination string
 * @src: source string
 * @n: numbers of characers to be concatinated on dest
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, len;

	for (i = 0; dest[i] != '\0'; i++)
		;
	len = i;
	for (i = 0; i < n; i++, len++)
	{
		dest[len] = src[i];
	}
	dest[len] = '\0';
	
	return (dest);
}
