#include "dog.h"
#include <stdio.h>

/**
 * init_dog - initialize the struct dog
 * @d: dog type
 * @name: name of the dog
 * @age: age
 * @owner: owner
 *
 * Return: nothing
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
