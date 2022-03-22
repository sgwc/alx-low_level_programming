#include "main.h"
#include <stdio.h>

/**
 * rev_string - rev sting
 * @s: string variable
 * Return: Always 0.
 */

void rev_string(char *s)
{
	int i;
	int len = 0;
	char *begin, *end, tmp;

	begin = s;
	end = s;
	len = _strlen(s);
	for (i = 0; i < len - 1; i++)
		end++;
	for (i = 0; i < len / 2; i++)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		end--;
		begin++;
	}
}
/**
 * _strlen - print string length
 * @s: pointer to string
 * Return: count
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;
	return (count);
}
