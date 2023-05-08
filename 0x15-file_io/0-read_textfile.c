#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - A function that reads a text file and prints it
 * to the standard output.
 * @filename: Name of the file to read
 * @letters: The maximum number of letters to read and print from the file
 *
 * Return: Number of letters read and printed to stdout
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
  int file;
  ssize_t read_check, wcount;
  char *buffer;

  /* Check if the filename is NULL */
  if (filename == NULL)
    return (0);

  /* Open the file */
  file = open(filename, O_RDONLY);
  if (file == -1)
    return (0);

  /* Allocate memory for the buffer */
  buffer = malloc(sizeof(char) * letters);
  if (buffer == NULL)
    {
      fprintf(stderr, "Failed to allocate memory for the buffer\n");
      return (0);
    }

  /* Read from the file into the buffer */
  read_check = read(file, buffer, letters);
  if (read_check == -1)
    {
      fprintf(stderr, "Failed to read from the file\n");
      free(buffer);
      return (0);
    }

  /* Write to stdout from the buffer */
  wcount = write(STDOUT_FILENO, buffer, read_check);
  if (wcount == -1 || read_check != wcount)
    {
      fprintf(stderr, "Failed to write to the standard output\n");
      free(buffer);
      return (0);
    }

  /* Free the memory allocated to the buffer */
  free(buffer);

  /* Close the file */
  if (close(file) == -1)
    {
      fprintf(stderr, "Failed to close the file\n");
      return (0);
    }

  /* Return the number of letters written to stdout */
  return (wcount);
}
