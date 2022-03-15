#include "main.h"
/**
 * print_last_digit - prints the last digit
 * @i : int whose last digit will be printedr
 * Return: n on success
 */
int print_last_digit(int i)
{
	i %= 10;
	if (i < 0)
		i *= -1;
	_putchar(i + '0');
	return (i);
}
