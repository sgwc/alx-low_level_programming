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

	for (i = 0; i <= 99; i++)
	{
		for (j = i + 1; j <= 99; j++)
		{	
			if (i < 9)
			{
				putchar('0' + i);
				putchar(48 + i);
			}
			putchar(48 + i);
			if (j < 9)
			{
				putchar('0' + j);
				putchar(48 + j);
			}
			putchar(48 + j);

			if (i == 89 && j == 99)
				break;

			putchar(' ');
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);

}
