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

	for (i = 0; s[i] != '\0'; i++)
		;
	for (i--; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
