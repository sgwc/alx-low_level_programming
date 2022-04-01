#include "main.h"

/**
 * _atoi - coverts a sting to an integer.
 * @s: string input
 * Return: integer numbers
 */
int first_digit_index(char *s);
int last_digit_index(char *s);

int _atoi(char *s)
{
	int j;
	int i = first_digit_index(s);

	unsigned int num = 0;

	int count = 0;

	int sign = 1;

	for (; i < last_digit_index(s); i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = num * 10 + (s[i] - '0');
		}
	}
	for (j = 0; j < first_digit_index(s); j++)
	{
		if (s[j] == 45)
			count++;
	}
	if ((count == 1) || ((count % 2) != 0))
		sign = -1;
	return (sign * num);
}

/**
 * first_digit_index - find the index of first index
 * @s: string input
 * Return: index
 */

int first_digit_index(char *s)
{
	int index;
	int i = 0;

	index = 0;
	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			index = i;
			break;
		}
	}
	return (index);
}
/**
 * last_digit_index - finds the index of the last digit
 * @s: String input
 * Return: index
 */
int last_digit_index(char *s)
{
	int index;
	int i;

	i = first_digit_index(s);
	index = i;

	for (i = i + 1; s[i] != '\0'; i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			index = i;
			break;
		}
	}
	index = i;
	return (index);
}
