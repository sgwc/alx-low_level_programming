#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - sums input args
 * @n: number of arguments
 *
 * Return: Always 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list list;
	unsigned int i, sum = 0;

	va_start(list, n);
	if (n != 0)
	{
		for (i = 0; i < n; ++i)
		{
			sum += va_arg(list, unsigned int);
		}
	}
	else
		return (0);
	va_end(list);
	return (sum);
}
