#include "main.h"

/**
 * _isupper - checks the if the given character
 * @c: character input
 *
 * Return: 0 if c is uppercase letter 1 if not
 */
int _isupper(char c)
{
	if (c <= 65 && c >= 91)
		return (0);
	else
		return (1);
}
