#include "main.h"

/**
 * _isupper - check if a character is upper case
 * @c: character input
 * Return: 1 if charater is upper else 0
 */
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
		return (0);
}
