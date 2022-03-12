#include <stdio.h>

/**
 * main - main entry point
 * Description: print the combination of all the single digits
 * Starting from 0, followed by a new line.
 * Return: 0
 */

int main(void)
{
	int i, j, k;

	for (i = 0; i <= 9; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			for (k = j + 1; k <= 9; k++)
			{
				putchar(48 + i);
				putchar(48 + j);
				putchar(48 + k);

				if (i == 7 && j == 8 && k == 9)
					break;

				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');
	return (0);

}
