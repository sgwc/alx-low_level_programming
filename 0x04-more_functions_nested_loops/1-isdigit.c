#include "main.h"

/**
 * _isdigit - check if a character is upper case
 * @c: character input
 * Return: 1 if charater is upper else 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}
