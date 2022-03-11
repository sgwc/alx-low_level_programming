#include <stdio.h>

/**
 * main - main entry point
 * Description: print the combination of all the single digits
 * Starting from 0, followed by a new line.
 * Return: 0
 */

int main(void)
{
	int i, j;
	for (i = 0; i <= 9; i++)
	{
		for(j = i + 1; j <= 9; j++)
		{
			putchar(48 + i);
			putchar(48 + j);
			if (i >= 8 && j >= 9)
				break;
			else
			{
				putchar(',');
				putchar(' ');
			}

		
		}
	}

	putchar('\n');

	return (0);
}
