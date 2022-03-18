#include "main.h"
/**
 * print_triangle - print triangle
 * @siize: size of the tirangle
 * Return: Always 0
 */
void print_triangle(int size)
{
	int j, k, p;
	//for (i = 0; i < size; i++)
	//{
		for (j = 0; j < size; j++)
		{
			if (j != (size - 1))
			{
				for (k = size - 1; k > j; k--)
					_putchar(' ');
			}
				for (p = 0; p <= j; p++)
					_putchar('#');
				_putchar('\n');

		}
	//}
	_putchar('\n');
}
