#include "main.h"
#include <stdio.h>

/**
 * _islower - checks the given charcter is in lower case
 * @c: chararcter to be checked
 *
 * Return: 0 if c is lower1, 1 if c is upper
 */
int _islower(int c)
{
	if ('c' >= 97 && 'c' <= 122)
		return (0);
	else
		return (1);
}
