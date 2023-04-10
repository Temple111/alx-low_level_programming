#include "main.h"


/**
 * read_textfile - reads a textfile and prints it to POSIX standard output
 * @filename: pointer to the file
 * @letters: number of letters in the function to be read
 * Return:0 for success
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int op;
	ssize_t nd, wr;
	char *buf;

	if (!filename)
		return (0);

	op = open(filename, O_RDONLY);

	if (op == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nd = read(op, buf, letters);
	wr = write(STDOUT_FILENO, buf, nd);

	close(op);

	free(buf);

	return (wr);
}
