
/**
 * create_file - creates a file with the given name and writes the
 *               given string to it
 * @filename: the name of the file to create
 * @text_content: the string to write to the file (can be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, num_words = 0;

	if (filename == NULL) /* check if filename is valid */
		return (-1);

	/* create the file with read and write permissions for user */
	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_descriptor == -1) /* check if file creation failed */
		return (-1);

	if (text_content != NULL) /* write content to file if it's not NULL */
	{
		/* count number of words in the string */
		while (text_content[num_words] != '\0')
			num_words++;

		/* write the string to the file */
		write_result = write(file_descriptor, text_content, num_words);
		if (write_result == -1) /* check if write failed */
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor); /* close the file */
	return (1);
}
