#include <stdio.h>

/**
 * main - prints all lower case alphabet in the stdout
 * Return: Always 0 (Success)
 */

int main(void)
{
	char ch = 'a';
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);

}
