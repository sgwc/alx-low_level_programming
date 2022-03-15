#include "main.h"

/**
 * print_alphabet - print alphabet to stdout
 * Return: on success 1
 */
void print_alphabet(void)
{
	int n;

	for (n = 'a'; n <= 'z'; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
