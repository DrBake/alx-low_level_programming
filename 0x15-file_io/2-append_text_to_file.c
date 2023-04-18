
/**
 * append_text_to_file - a function that appends text at the end of a file
 *
 * @filename: the file to add data to
 * @text_content: the text content to add to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int file, app_status, words = 0;

    if (filename == NULL) /* Check if file is present */
        return (-1);

    /* Open file in append mode with write rights */
    file = open(filename, O_APPEND | O_WRONLY);
    if (file == -1) /* Check if file is present */
        return (-1);

    if (text_content) /* Append content to file if it's not NULL */
    {
        while (text_content[words] != '\0') /* Find number of words */
            words++;

        /* Append to file */
        app_status = write(file, text_content, words);
        if (app_status == -1) /* Check if append was a success */
            return (-1);
    }

    close(file); /* Close file */
    return (1);
}
