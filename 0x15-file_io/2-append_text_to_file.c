#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file to append to
 * @text_content: string to append to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written = 0, append_status;

	if (filename == NULL) /* Check if filename is present */
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1) /* Check if file is present */
		return (-1);

	if (text_content != NULL) /* Append content to file if its not NULL */
	{
		while (*(text_content + bytes_written) != '\0')
			bytes_written++;

		append_status = write(fd, text_content, bytes_written); /* Append to file */
		if (append_status == -1) /* Check if append was a success */
			return (-1);
	}

	close(fd); /* Close file */
	return (1);
}
