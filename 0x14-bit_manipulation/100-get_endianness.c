#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 BE , 1 LE
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *c = (char *) &n;
	return ((int)*c);
}
