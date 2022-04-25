#include <stdio.h>
/**
 * before_main - prints before main
 *
 * Return: Nothing
 */

void __attribute__ ((constructor)) before_main()
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
