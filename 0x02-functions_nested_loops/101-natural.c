#include <stdio.h>
/**
 * main - check for multiples of 3 and 5
 * Return : 0 on sucess
 */
int main(void)
{
	int sum;
	int i;

	sum = 0;

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
			sum = sum + i;
	}
	printf("%d\n", sum);
	return (0);
}
