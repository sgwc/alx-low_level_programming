#include "main.h"

/**
 * print_sign - print sign of the given interger
 * @n : interger number
 * Return : 1 if n is greater than 0 and 0 if n is 0 and 
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
	
}
