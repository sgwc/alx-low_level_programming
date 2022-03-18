#include "main.h"

/**
 * print_numbers - list all digits form 0 - 9
 * 
 * Return: Always 0
 */

void print_most_numbers(void)
{
	int i;
	
	for (i = 48; i <= 57; i++)
	{
		if (i != 50 && i != 52)
			_putchar(i);
	}
	_putchar('\n');
}
