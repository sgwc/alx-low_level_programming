#include <stdio.h>
#include "main.h"

/**
 * clear_bit - reset bit of n at a index
 * @n: number
 * @index: position of the bit
 *
 * Return: Always 0.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;
	
	mask = 1UL << index;

	if (index > 63)
		return (-1);
	*n = (~mask) & *n;
	return (1);
}
