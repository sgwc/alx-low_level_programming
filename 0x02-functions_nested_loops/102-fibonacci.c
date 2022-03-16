#include <stdio.h>

/**
 * main - main entry point
 *
 * fibonacci : prints the first 50 fibonacci serious
 * Return : return 0 (success)
 */

int main(void)
{
	int i;
	unsigned long sum;
	
	unsigned long fb[50];

	for (i = 0; i < 50; i++)
	{
		if (i < 2)
		{
			fb[i] = 1;
		}
		else 
		{
			fb[i] = fb[i - 1] + fb[i - 2];
		}
	}

	sum = fb[49];
	
	printf("%lu\n", sum);
	return (0);
}
