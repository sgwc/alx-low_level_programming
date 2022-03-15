#include "main.h"
/**
 * _islower - checks for lowercase 
 * @c: character c
 * Return: 1 if c is lower  0 if otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
