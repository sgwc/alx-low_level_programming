#include "main.h"
/**
 * print_times_table - prints time table of 9
 *@n : interger number between 0 and 15
 * Return : Always 0
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n <= 0 || n >= 15)
	{
		return;
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				p = i * j;
				if (j == 0)
				{
					_putchar(p + '0');
				}
				else
				{
					if (p < 10)
					{
						_putchar(',');
						_putchar(' ');
						_putchar(' ');
						_putchar(' ');
						_putchar(p + '0');
					}
					else if( p >=10 && p < 100)
					{
						_putchar(',');
						_putchar(' ');
						_putchar(' ');
						_putchar((p / 10) + '0');
						_putchar((p % 10) + '0');
					}
					else
					{
						_putchar(',');
						_putchar(' ');
						_putchar((p / 100) + '0');
						_putchar(((p / 10)% 10) + '0');
						_putchar((p % 10) + '0');
					}
				}
			}
			_putchar('\n');
		}
	}
}
