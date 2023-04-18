
/**
 * create_file - creates a file with the given filename and writes the
 *               given text content to it.
 *
 * @filename: name of file to create
 * @text_content: string to write to file
 *
 * Return: 1 on success OR -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int file, write_status, words = 0;

    /* Check if filename is present */
    if (filename == NULL)
        return (-1);

    /* Open file in write mode and create if it doesn't exist, else truncate */
    file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file == -1)
        return (-1); /* Check if file creation was a success */

    /* Write content to file if it's not NULL */
    if (text_content)
    {
        /* Find number of words in text content */
        while (text_content[words] != '\0')
            words++;

        /* Write to file */
        write_status = write(file, text_content, words);
        if (write_status == -1)
        {
            close(file);
            return (-1); /* Check if write was a success */
        }
    }

    close(file); /* Close file */
    return (1);
}
