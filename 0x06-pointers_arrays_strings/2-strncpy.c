#include "main.h"

/**
 * _strncpy - does string copy
 * @dest: destination string
 * @src: source string
 * @n: numbers of characers to be concatinated on dest
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; (i < n) && (src[i] != '\0'); i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	
	return (dest);
}
