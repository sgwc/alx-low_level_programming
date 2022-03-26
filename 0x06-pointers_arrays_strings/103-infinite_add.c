#include "main.h"

/**
 * infinite_add - infinite add
 * @n1: number 1
 * @n2: number 2
 * @r: result buffer
 * @size_r: size r
 *
 * Return: r
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	
	int i, j;
	int n;

	int sum, carry;

	for (i = 0; n1[i] != '\0'; i++)
		;

	for (j = 0; n2[j] != '\0'; j++)
		;
	for (n = size_r ; n >= 0; n--)
	{
		sum = (n1[n] - 48) + (n2[n] - 48) ;
		if (sum  / 10 != 0)
		{
			carry = sum / 10;
			sum = sum % 10;
		}
		
		r[n] = sum + carry;
		carry = 0;		
	}
	
	return (r);
}
