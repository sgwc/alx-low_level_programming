#include "main.h"
#include <stddef.h>

/**
 * _strchr - find the char c in s
 * @s: input string
 * @c: character to look for in s
 *
 * Return: first occorenc of
 */

char *_strchr(char *s, char c)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (NULL);
}
