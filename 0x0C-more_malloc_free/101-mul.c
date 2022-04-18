#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the multiplication of two integrs
 * @argc:number of arguments
 * @argv: Arguments passed
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	unsigned long mul;
	int i, j;

	if (argc == 3)
	{
		for (i = 1; i < argc; i++)
		{
			for (j = 0; argv[i][j] !='\0'; j++)
			{
				if (argv[i][j] > 57 || argv[i][j] < 48)
				{
					print("Error\n");
					exit(98);
				}
			}
		}

		mul = atol(argv[1]) * atol(argv[2]);
		printf("%lu\n", mul);
		return (0);
	}
	else
	{
		printf("Error\n");
		exit (98);
	}
}
