#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - checks the newly created mem block
 * @b: size of the mem
 *
 * Return: pointer on succuss (98 if failed)
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;
	
	ptr = malloc(b);
	if(ptr == NULL)
	{
		exit(EXIT_FAILURE);	
	}
	
	return (ptr);
}
