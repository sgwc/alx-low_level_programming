#include "main.h"

/**
 * swap_int - swaps the values of two integer variable
 * @a : first integer variable
 * @b : the second integer variable
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int interim;

	interim = *a;
	*a = *b;
	*b = interim;
}
