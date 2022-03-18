#include "main.h"

/**
 * more_numbers - list all digits form 0 - 9, except 2 and 4
 * 
 * Return: Always 0
 */

void more_numbers(void)
{
	int i, j;
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 15; i++)
		{
			if(i <= 9)
				_putchar(i);
			else
				_putchar('1' + i % 10);
		}
		_putchar('\n');
	}
}
