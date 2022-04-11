#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_dog - creates new dog
 * @name: name
 * @age: age
 * @owner
 *
 * Return: new dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *n_dog;
	char *dog_name = name;
	char *dog_owner = owner;

	n_dog = malloc(sizeof(dog_t));

	if(n_dog == NULL)
	{
		return (NULL);
	}
	n_dog->name = dog_name;
	n_dog->age = age;
	n_dog->owner = dog_owner;

	return (n_dog);
}
