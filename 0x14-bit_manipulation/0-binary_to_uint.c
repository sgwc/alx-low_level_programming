#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

double _pow(double, double);
/**
 * binary_to_uint - converts binary to int
 * @b: binary number of stirng type
 *
 * Return: int of b
 */
unsigned int binary_to_uint(const char *b)
{
	int len;
	int i, j; 
	unsigned int n, dec = 0;

	for (len = 0; b[len] != '\0'; len++)
		;

	j = len - 1;
	for (i = 0; i < len; i++,j--)
	{
		if (!(b[i] == 48 || b[i] == 49))
			return  (0);
		else
			n = b[i] - '0';
		dec += n * _pow(2, j);
	}
	return (dec);
}

/**
 * _pow - computes exponent
 * @base: base
 * @exp: expone
 *
 * Return: power of base to exp
 */
double _pow(double base, double exp)
{
	double pow = 1.0;
	int i;
	if (exp < 0)
	{	
		exp = -1 * exp;
		return (1/_pow(base, exp));	
	}
	else
	{
		for (i = 0; i < (int)exp; i++)
		{
			pow *= base; 
		}
	}
	return (pow);
}
