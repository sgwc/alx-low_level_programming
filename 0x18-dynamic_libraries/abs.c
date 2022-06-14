#include "main.h"
#include <stdio.h>

/**
 * -abs - returnes the absolute value of a number
 *  @n: number
 *
 *  Return: absolute value
 */
int _abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
