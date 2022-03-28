#include "main.h"

/**
 * _memset - fill memeory area with a constant byte.
 * @s:given array
 * @b: the constant byte to be filled with
 * @n: the num of memory areas
 *
 * Return: pointer s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}	
	return (s);
}
