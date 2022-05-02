#include "main.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to stdio.
 * @filename: file to be read
 * @letters: number of letters it should read and print.
 *
 * Return: number of letters
 */
size_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int frd, fwr;
	char *buff;

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);
	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY, 700);
	if (fd == -1)
		return (0);
	frd = read(fd, buff, letters);
	if (frd == -1)
		return (0);
	fwr = write(STDOUT_FILENO, buff, frd);
	if (fwr == -1)
		return (0);
	close(fd);
	free(buff);
	return (fwr);
}
