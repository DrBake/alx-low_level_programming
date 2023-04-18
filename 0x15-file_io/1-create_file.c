#include "main.h"

/**
 * create_file - creates a file and writes text to it
 * @filename: the name of the file to create
 * @text_content: the text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file, write_status, words = 0;

	if (filename == NULL) /* check if filename is present */
		return (-1);

	/* open file by creating it and if it exists write but truncate to 0 */
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1) /* check if file creation was a success */
		return (-1);

	if (text_content) /* write content to file if it's not NULL */
	{
		/* find the number of words in the text_content string */
		while (text_content[words] != '\0')
			words++;

		/* write text_content to file */
		write_status = write(file, text_content, words);
		if (write_status == -1) /* check if write was a success */
		{
			close(file);
			return (-1);
		}
	}

	close(file); /* close file */
	return (1);
}
