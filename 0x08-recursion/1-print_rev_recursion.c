#include "main.h"

/**
 * _print_rev_recursion - prints a string, followed by new line
 * @s: string input to be printed
 *
 * Return: nothing
 */

void _print_rev_recursion(char *s)
{
	char *r;
	r = &(s == '\0');
	if (r == s)
	{
		_putchar(*r);
		_puts_recursion(r - 1);
	}
	else
		_putchar('\n');
}
