#include "main.h"

/**
 * _printf - prints input to the std io
 * @format: 
 *
 * Return: characters printed on sucess
 */
int _printf(const char *format, ...)
{
	int count;
	int result;

	va_list list;
	if (!format)
		return (0);
	va_start(list, format);
	result = 0;
	count = -1;

	while (format[++count])
	{
		if (format[count] == '%')
		{
			result += formats(list, format[count + 1]);
			count++;
		}
		else
			result += _putchar(format[count]);
	}
	va_end(list);
	return (result);
}
