#include "main.h"

/**
 *
 * 
 */
int _strlen(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
/**
 *
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/**
 *
 *
 */
int _putstr(char *s)
{
	int i;
	
	i = 0;
	if (!s)
		return(_putstr("(nil)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
/**
 *
 *
 */
int _putnbr(int n)
{
	char *s;
	int res;

	s = _itoa(n);
	res = _putstr(s);
	free(s);
	return (res);
}
/**
 *
 *
 */
int formats(va_list list, char c)
{
	if (c == 's')
		return (_putstr(va_arg(list, char *)));
	if (c == 'c')
		return (_putchar((char)va_arg(list, int)));
	if (c == 'i' || c == 'd')
		return (_putnbr((va_arg(list, int))));
	if (c == '%')
		return (_putchar('%'));
	return (0);
}
