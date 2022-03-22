#include "main.h"

/**
 * puts_half - print the second half
 * @str: string input
 * Return: Always 0.
 */

void puts_half(char *str)
{
	int i, n, len;

	len = _strlen(str);

	if ((len % 2) == 0)
	{
		n = len / 2;
		for (i = n; i < len; i++)
			_putchar(str[i]);
	}
	else
	{
		n = (len - 1) / 2;
		for (i = n + 1; i < len; i++)
			_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * _strlen - puts string length
 * @s: pointer to string
 * Return: Void
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;
	return (count);
}
