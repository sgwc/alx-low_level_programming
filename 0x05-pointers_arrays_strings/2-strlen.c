#include "main.h"

/**
 * _strlen - finds the lengh of a string variable
 * @s: string variable
 * Return: the length of the s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;

	}
	return (len);
}
