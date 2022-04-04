#include "main.h"

/**
 * create_array - creates an array of chars
 * @size: size of the memory to be allocated
 * @c: character to initalize the array
 *
 * Return: pointer to newly created array
 *
 */

char *create_array(unsigned int size, char c)
{
	char *s;
	s = melloc(size * sizeof(char));
	s[o] = c;
	return (s);
}
