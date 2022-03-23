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

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	
	return (dest);
}
