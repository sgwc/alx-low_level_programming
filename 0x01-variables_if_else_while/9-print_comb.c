#include <stdio.h>

/**
 * main - main entry point
 * Description: print the combination of all the single digits
 * Starting from 0, followed by a new line.
 * Return: 0
 */

int main(void)
{
	int n = 0;

	while( n <= 9)
	{
		putchar(48 + n);
		if (n != 9)
		{
			putchar(',');
			putchar(' ');
		}
		else
			break;
		n++;
	}

	putchar('\n');

	return (0);
}
