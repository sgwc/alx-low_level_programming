#include "main.h"
#include <stdio.h>

/**
 * _puts - prints a string to the stdio
 * @str: string variable
 * Return: Always 0.
 */
void _puts(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		printf("%c", str[len]);
		len++;

	}
	printf("\n");
}
