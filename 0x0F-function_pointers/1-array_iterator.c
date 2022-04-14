#include "function_pointers.h"
#include <stdio.h>
#include <stddef.h>

/**
 * array_iterator - execute a function given as a parameter
 * @array: array input
 * @size: size of the array
 * @action: pointer to function
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	i = 0;

	while (i < size && array != NULL && action != NULL)
	{
		action(array[i]);	
		i++;
	}
}
