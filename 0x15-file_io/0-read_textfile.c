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
	char *b;

	b = malloc(sizeof(char) * letters); /* b = buffer */

	if (filename == NULL)
		return (0);
	if (b == NULL)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, b, letters);
	wr = write(STDOUT_FILENO, b, rd);

	if (wr != rd || wr == -1 || op == -1 || rd == -1)
	{
		free(b);
		return (0);
	}

		free(b);
		close(op);
		return (wr);
}
