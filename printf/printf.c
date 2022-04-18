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
	int resut;

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
			result += main_sorter(list, format[count + 1]);
			count++;
		}
		else
			result += write(1, format[count], 1);
	}
	va_end(list);
	return (result);
}
