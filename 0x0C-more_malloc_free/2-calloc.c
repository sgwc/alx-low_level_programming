#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocat memory block used for array
 * @nmemb: array input
 * @size: size of array
 *
 * Return: pointer to a address on success
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);

	if (ptr == NULL)
	{
		return (NULL);
	}

	memset(ptr, 0, size * nmemb);

	return (ptr);
}
