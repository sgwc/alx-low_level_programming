#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: stirng input
 * @accept:the characters to lookfor
 *
 * Return: number of occurrences
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i, j;

	for (i = 0; accept[i] != '\0'; i++)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			if (accept[i] == s[j])
			{
				count++;
				break;
			}
		}
	}
	return (count);
}
