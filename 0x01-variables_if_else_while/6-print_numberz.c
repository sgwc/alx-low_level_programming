#include <stdio.h>

/**
 * main - prints all lower case alphabet in the stdout
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n = 0;

	while (n <= 9)
	{
		putchar(48 + n);
		n++;
	}
	putchar('\n');
	return (0);

}
