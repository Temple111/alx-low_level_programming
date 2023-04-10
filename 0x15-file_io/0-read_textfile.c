#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a textfile and prints it to POSIX standard output
 * @filename: pointer to the file
 * @letters: number of letters in the function to be read
 * Return:0 for success
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t op, rd, wr;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(letters * sizeof(char));
	if (buff == NULL)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, buff, letters);
	wr = write(STDOUT_FILENO, buff, rd);

	if (op == -1 || rd == -1 || wr == -1 || wr != r)
	{
		free(buff);
		return (0);
	}

	free(buff);
	close(op);

	return (wr);
}
