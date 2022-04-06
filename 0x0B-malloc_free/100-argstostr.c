#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - prints arguments passed
 * @ac: counts passed arguments
 * @av: pointer for arguments array
 *
 * Return: pointer
 */
char *argstostr(int  ac, char **av)
{
	char *s;
	int i, count = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		count++;
	}

	count = count + 1;
	s = malloc(sizeof(char) * count);

	if (s == NULL)
	{
		return (NULL);
	}
	s = av[0];
	/*s = strcat(s, "\n");*/

	for (i = 1; i < ac; i++)
	{
		/*s = strcat(s, "\n");*/
		s = strcat(s, av[i]);
	}

	return (s);
}
