#include "main.h"

/**
 * create_file - creates a function that creates a file
 * @filename: a pointer to filename
 * @text_content: pointer to content of text
 * Return: 0 for success
 */

int create_file(const char *filename, char *text_content)
{
	int op, wr, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[len];)
			l++;
	}

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(op, text_content, l);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
