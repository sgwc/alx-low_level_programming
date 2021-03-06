#include "dog.h"
#include <stdio.h>

/**
 * print_dog - print elements of dog
 * @d: dog type object
 *
 * Return: nothing
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		if(d->name == NULL || d->name == '')
		{
			printf("Name: (nil)\n");
		}
		else
			printf("Name: %s\n", d->name);

		if(d->age == 0)
		{
			printf("Age: (nil)\n");
		}
		else
			printf("Age: %.6f\n", d->age);
		
		if(d->owner == NULL || d->owner == '')
		{
			printf("Owner: (nil)\n");
		}
		else
			printf("Owner: %s\n", d->owner);
	}
}
