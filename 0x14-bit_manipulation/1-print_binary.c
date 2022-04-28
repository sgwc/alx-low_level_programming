#include <stdio.h>

/**
 * print_binary - prints bin
 * @n: number
 *
 * Return: Nothing
 */
void print_binary(unsigned long int n)
{
	if (n >> 1)
	{
		print_binary(n >> 1);
	}
	putc((n & 1) ? '1' : '0', stdout);
}
