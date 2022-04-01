#include "main.h"
#include <stdio.h>

/**
 * main - print the number of arguments
 * @argc:number of arguments
 * @argv: Arguments passed
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char __attribute__((unused)) *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
