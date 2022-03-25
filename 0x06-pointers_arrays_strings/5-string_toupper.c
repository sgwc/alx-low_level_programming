#include "main.h"
/**
 * string_toupper - converts all lowercase letters of a string to uppercase.
 * @a: string
 * Return: the converted string
 */

char *string_toupper(char *a)
{
	int i;

	for (i = 0; a[i] !='\0'; i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] = a[i] - 32;
		}
	}
	return (a);
}
