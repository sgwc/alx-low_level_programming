#include <stdio.h>
#include "main.h"

/**
 * get_bit - get bit at position index
 * @n: number
 * @index: index of the bit
 *
 * Return: bit at poition index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int mask = 1 << index;
	
	if (index > 63)
		return (-1);

	return ((n & mask) >> index);
}
