#define MAXSIZE 1024 /* maximum buffer size for copying contents */


/**
 * __exit - prints error messages and exits with exit number
 *
 * @error: either the exit number or file descriptor
 * @str: name of either file_in or file_out
 * @fd: file descriptor
 *
 * Return: 0 on success
*/
int __exit(int error, char *str, int fd)
{
	switch (error)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(error);
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
			exit(error);
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
			exit(error);
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(error);
		default:
			return (0);
	}
}

/**
 * main - create a copy of file
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 for success.
*/
int main(int argc, char *argv[])
{
	int file_in, file_out;
	int read_stat, write_stat;
	int close_in, close_out;
	char buffer[MAXSIZE];

	/* if the number of arguments is not 3 */
	if (argc != 3)
		__exit(97, NULL, 0);

	/* open the file from which contents will be copied */
	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		__exit(98, argv[1], 0);

	/* open/create the file to which contents will be copied */
	file_out = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_out == -1)
		__exit(99, argv[2], 0);

	/* read contents from file_in and write to file_out */
	while ((read_stat = read(file_in, buffer, MAXSIZE)) != 0)
	{
		if (read_stat == -1) /* if reading from file_in fails */
			__exit(98, argv[1], 0);

		/* copy and write contents to file_out */
		write_stat = write(file_out, buffer, read_stat);
		if (write_stat == -1) /* if writing to file_out fails */
			__exit(99, argv[2], 0);
	}

	/* close file_in and file_out */
	close_in = close(file_in);
	if (close_in == -1)
		__exit(100, NULL, file_in);

	close_out = close(file_out);
	if (close_out == -1)
		__exit(100, NULL, file_out);

	return (0);
}
