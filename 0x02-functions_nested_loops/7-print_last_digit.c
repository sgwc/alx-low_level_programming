#include "main.h"
/**
 * print_last_digit - prints the last digit
 * @n : char of numer
 * Return: 0 success
 */
int print_last_digit(int n)
{
	int i;
	i = n % 10;
	if (i < 0)
		i *= -1;
	return (i);
}
