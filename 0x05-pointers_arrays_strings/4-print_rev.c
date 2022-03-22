#include "main.h"
#include <stdio.h>

/**
 * print_rev - prints a string to the stdio
 * @s: string variable
 * Return: Always 0.
 */

void print_rev(char *s)
{
	int i;
	int len;

	while ( s[i] != '\0')
	{
		i++;
	}
	len = i;

	while (len >= 0)
	{
		_putchar('0' + s[len]);
		len--;

	}
	_putchar('\n');
}
