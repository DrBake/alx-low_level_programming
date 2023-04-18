#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * error_exit - function that prints an error message and exits
 *
 * @error_code: the exit status
 * @message: the error message to print
 */
void error_exit(int error_code, char *message)
{
        dprintf(STDERR_FILENO, "%s\n", message);
        exit(error_code);
}

/**
 * main - function that copies the content of a file to another file
 *
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, or the appropriate error code on failure
 */
int main(int argc, char **argv)
{
        int fd_from, fd_to, bytes_read, bytes_written;
        char buf[BUFSIZE];

        /* Check the number of arguments */
        if (argc != 3)
                error_exit(97, "Usage: cp file_from file_to");

        /* Open the source file */
        fd_from = open(argv[1], O_RDONLY);
        if (fd_from == -1)
                error_exit(98, "Error: Can't read from file %s", argv[1]);

        /* Create or truncate the destination file */
        fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
        if (fd_to == -1)
                error_exit(99, "Error: Can't write to %s", argv[2]);

        /* Copy the content of the source file to the destination file */
        while ((bytes_read = read(fd_from, buf, BUFSIZE)) > 0)
        {
                bytes_written = write(fd_to, buf, bytes_read);
                if (bytes_written != bytes_read)
                        error_exit(99, "Error: Can't write to %s", argv[2]);
        }

        /* Check if there was an error reading the source file */
        if (bytes_read == -1)
                error_exit(98, "Error: Can't read from file %s", argv[1]);

        /* Close the files */
        if (close(fd_from) == -1)
                error_exit(100, "Error: Can't close fd %d", fd_from);
        if (close(fd_to) == -1)
                error_exit(100, "Error: Can't close fd %d", fd_to);

        return (0);
}
