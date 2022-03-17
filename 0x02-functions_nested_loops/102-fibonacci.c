#include <stdio.h>

/**
 * main - main entry point
 * Return: 0 on success
 */

int main(void)
{
	int i;
	unsigned long fb[51];

	for (i = 0; i < 51; i++)
	{
		if (i < 2)
		{
			fb[i] = 1;
		}
		else
		{
			fb[i] = fb[i - 1] + fb[i - 2];
		}
		if (i >= 1 && i < 50)
			printf("%lu, ", fb[i]);
		else if (i >= 50)
			printf("%lu", fb[i]);
	}

	printf("\n");

	return (0);
}
