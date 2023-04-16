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
	ssize_t rd, wr;
	char *bf;

	if (!filename)
		return (0);

	op = open(filename, O_RDONLY);

	if (op == -1)
		return (0);

	bf = malloc(sizeof(char) * (letters));
	if (!bf)
		return (0);

	rd = read(op, bf, letters);
	wr = write(STDOUT_FILENO, bf, rd);

	close(op);

	free(bf);

	return (wr);
}
