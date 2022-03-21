#include "main.h"
#include <stdio.h>

/**
 * print_rev - prints a string to the stdio
 * @s: string variable
 * Return: Always 0.
 */
void print_rev(char *s)
{
	int len;

	len = _strlen(s);
	while (len >= 0)
	{
		printf("%c", s[len]);
		len--;

	}
	printf("\n");
}
