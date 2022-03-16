#include "main.h"
#include <stdio.h>
/**
 * print_times_table - prints time table of 9
 * @n: interger number between 0 and 15
 * Return : Always 0
 */
void print_times_table(int n)
{
	int i, j, p;

	if (n < 0 || n > 15)
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
				if (p > 0)
				{
					if (p > 9 && p <= 99)
					{
						printf(",  %d", p);
					}
					else if(p > 99)
					{
						printf(", %d", p);
					}
					else
					{
						printf(",   %d", p);
					}
				}
				else
				{
					printf("%d", p);
					if (j != n && i == 0)
					{
						printf(",   ");
					}
				}
			}
			printf("\n");
		}
	}
}
