#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - append text and only if file exists
 * @filename: file
 * @text_content: appends this content into file
 * Return: 1 on success, -1 on error
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int n_wrote;
	size_t len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (!text_content)
	{
		close(fd);
		return (1);
	}

	while (text_content[len] != '\0')
		len++;

	n_wrote = write(fd, text_content, len);
	if (n_wrote == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

