#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints char to the stdio
 * @c: char to print
 *
 * Return: 0 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
