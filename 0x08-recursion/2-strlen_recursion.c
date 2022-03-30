#include "main.h"

/**
 * _strlen_recursion - calculate string length
 * @s: string input
 *
 * Return: length of the given string
 */
int _strlen_recursion(char *s)
{
	int length;
	length = 0;

	if (*s != '\0')
	{
		length = length + _strlen_recursion(s++);
	}	

	return (length);
}
