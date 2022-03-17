#include <stdio.h>

/**
 * main - main entry point
 * Return: 0 on success
 */
int main(void)
{
	int i;
	unsigned long sum, pv, cv;

	for(i = 0; i < 99; i++)
	{
		if (i == 0)
		{	
			pv = 0;
			cv = 1;
			sum = pv + cv;
			pv = cv;
			cv = sum;
			printf("%lu, ", sum);
		}
		else if ( i > 0 && i < 98)
		{
			sum = pv + cv;
			pv = cv;
			cv = sum;
			printf("%lu, ", sum);
		}
		else 
		{
			sum = pv + cv;
			printf("%lu", sum);
		}
	}
	printf("\n");
	return (0);
}
