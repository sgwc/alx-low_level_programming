#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * error_file - checks if files can be opened.
 * @file_from: file_from
 * @file_to: file_to.
 * @argv: arguments vector.
 * Return: nothing
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - check the code
 * @ac: number of arguments
 * @av: arguments vector.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int f_from, f_to;
	ssize_t nchars, nwr;
	char buff[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_from = open(av[1], O_RDONLY);
	f_to = open(av[2], O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0664);
	error_file(f_from, f_to, av);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(f_from, buff, nchars);
		if (nchars == -1)
			error_file(-1, 0, av);
		nwr = write(f_to, buff, nchars);
		if (nwr == -1)
			error_file(0, -1, av);
	}

	if (close(f_from) < 0)
	{
		dprintf(STDERR_FILENO,"Error: cant close fd %d\n", f_from);
		exit(100);
	}
	if (close(f_to) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_to);
		exit(100);
	}
	return (0);
}
