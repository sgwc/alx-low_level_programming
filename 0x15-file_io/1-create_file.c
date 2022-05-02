#include "main.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - create a file
 * @filename: name of the file
 * @text_content: string to be written on the file
 *
 * Return: 1 on Success -1 if failed
 */

int create_file(const char *filename, char *text_content)
{
	int fd, fr;
	int i;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (i = 0; text_content[i]; i++)
			;
		fr = write(fd, text_content, i);
		if (fr == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
