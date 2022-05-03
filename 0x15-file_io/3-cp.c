#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int f_from, f_to;
	int fread;
	char buff[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = open(av[1], O_RDONLY, 0664);
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	f_to = open(av[2],O_CREAT | O_TRUNC | O_WRONLY, 0664);
	while ((fread = read(f_from, buff, 1024)) > 0)
	{
		if (write(f_to, buff, fread) != fread || f_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (fread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (close(f_from) < 0)
	{
		dprintf(STDERR_FILENO,"Error: cant close fd %d\n", f_from);
		exit(100);
	}
	if (close(f_to) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_to);
	}
	return (0);
}
