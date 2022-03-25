#include "main.h"

/**
 * cap_string - Capitalizess all words of the given string
 * @a: stirng input
 * Return: string
 */
char *cap_string(char *a)
{
	int i;

	if (a[0] >= 97 && a[0] <= 122)
		a[0] = a[0] - 32;
	for (i =  1; a[i] != '\0'; i++)
	{
		if (a[i - 1] == 32 || a[i - 1] == '\t' || a[i - 1] == '\n' || a[i - 1] == 44 || a[i - 1] == 46 || a[i - 1] == 59 || a[i - 1] == 33 || a[i - 1] == 63 || a[i - 1] == 34 || a[i - 1] == 40 || a[i - 1] == 41 || a[i - 1] == 123 || a[i - 1] == 125)
		{
			if(a[i] >= 97 && a[i] <= 122)
				a[i] = a[i] - 32;
		}
	}
	return (a);
}
