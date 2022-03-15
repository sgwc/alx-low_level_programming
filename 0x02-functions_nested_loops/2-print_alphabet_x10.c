#include "main.h"

/**
 * print_alphabet_x10- print alphabets to stdout
 * Return: Always 0 
 */
void print_alphabet_x10(void)
{
	int i, j;

	i = 0;
	
	while (i < 10)
	{	
		j = 'a';
		
		while (j <= 'z')
		{
			_putchar(j);
			j++;
		}
		_putchar('\n');
		i++;
	}

}
