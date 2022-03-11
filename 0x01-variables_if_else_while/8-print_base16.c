#include <stdio.h>

/**
 * main - prints all lower case alphabet in the stdout
 * Return: Always 0 (Success)
 */

int main(void)
{
	char d = '0';
	char c = 'a';

	while (d <= '9')
	{
		putchar(d);
		d++;
	}

	while (c <= 'f')
	{
		putchar(c);
		c++;	
	}
	putchar('\n');
	return (0);

}
