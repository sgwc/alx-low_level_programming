#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints name
 * @name: name input
 * @f: funciotn pinter
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL)
		f(name);
}
