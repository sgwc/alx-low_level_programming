#include <stdio.h>
/**
 * main - s
 * Return : 
 */
int main(void)
{
	unsigned long sum;
	unsigned long m3;
	unsigned long m5;
	int i;

	for (i = 1; i < 1024; i++)
	{
		m3 = 3 * i;
		m5 = 5 * i;
		sum = m3 + m5;
	}
	printf("%lu\n", sum);
	return (0);
}
