#include "main.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * append_text_to_file - append text at the end a file
 * @filename: name of the file
 * @text_content: text to write to
 *
 * Return: 1 on sucess, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, fwr, i;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_APPEND | O_RDWR, 0664);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (i = 0; text_content[i]; i++)
			;
		fwr = write(fd, text_content, i);
		if (fwr == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
