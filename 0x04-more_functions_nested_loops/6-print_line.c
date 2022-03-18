#include "main.h"

/**
 * print_line - print line
 * @n: integer to print
 * Return: void
 */

void print_line(int n)
{
	int c = 0;

	while ((c < n) && (n > 0))
	{
		_putchar('_');
		c++;
	}
	_putchar('\n');
}
