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
	int i, length;
	for (length = 0; s[length] != '\0'; length++)
		;
	length++;
	for (i = 0; i < length; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (NULL);
}
