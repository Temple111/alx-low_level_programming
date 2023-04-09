#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - reads a textfile and prints it to the POSIX standard output
 * @filename: pointer to filename to be printed
 * @letters: letters to be printed
 * Return: 0 for success
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t op, rd, wr;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd)

	if (op == -1 || rd == -1 || wr == -1 || wr != rd)
	{
		free(buffer);
		return (0);
	}

		free(buffer);
		close(op);

		return (wr);
}
