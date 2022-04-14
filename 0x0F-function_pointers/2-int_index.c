#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searchs for an integer
 * @array: array input
 * @size: size of the array
 * @cmp: function to pointer
 *
 * Return: index
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size < 1 || array == NULL || cmp == NULL)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]))
		{
			break;
		}
		i++;
	}
	if (i >= size)
		return (-1);
	else
		return (i);
}
