#include "main.h"
#include <stdio.h>

/**
 * main - list the arguments
 * @argc:number of arguments
 * @argv: Arguments passed
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
int i;
if (argc > 0)
{
for (i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}
}
return (0);
}
