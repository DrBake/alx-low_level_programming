
#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

/* This header file contains function prototypes for file-related
 * operations such as reading, creating, and appending text to files.
 * These functions can be used in various applications that require file
 * manipulation. */

/* read_textfile - A function that reads a text file and prints it to
 * the standard output.
 *
 * @filename: Name of the file to read
 * @letters: The maximum number of letters to read and print from the file
 *
 * Return: Number of letters read and printed to stdout
 */

ssize_t read_textfile(const char *filename, size_t letters);

/* create_file - A function that creates a file with the specified name
 * and writes the specified text content to it.
 *
 * @filename: Name of the file to create
 * @text_content: The text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content);

/* append_text_to_file - A function that appends text content to an
 * existing file.
 *
 * @filename: Name of the file to append to
 * @text_content: The text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content);

#endif
