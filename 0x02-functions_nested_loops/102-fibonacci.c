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
		printf("%lu, ",fb[i]);
	}

	printf("\n");

	return (0);
}
