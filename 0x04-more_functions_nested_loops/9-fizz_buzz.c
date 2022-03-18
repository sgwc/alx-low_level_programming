#include <stdio.h>

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3) == 0)
		{
			if (((i % 3) == 0) && ((i % 5) == 0))
			{
				printf("FizzBuzz ");
			}
			else
			{
				printf("Fizz ");
			}
		}
		else if ((i % 5) == 0)
		{
			printf("Buzz");
			if (i != 100)
			{
				printf(" ");
			}
		}
		else
		{
			printf("%d ", i);
		}
	}
	putchar('\n');
	return (0);
}
