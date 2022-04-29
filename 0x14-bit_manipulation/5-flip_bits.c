#include <stdio.h>
#include "main.h"

/**
 * flip_bits - number of bits you would need to flip
 * @n: first number
 * #m: second number
 *
 * Return: numbero of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int curr;
	unsigned long int bit_diff = n ^ m;

	for (i = 0; i <= 63; i++)
	{
		curr = bit_diff >> i;
		if (curr & 1)
			count++;
	}
	return (count);
}
