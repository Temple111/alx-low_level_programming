#include "main.h"

/**
 * create_file - creates a function that creates a file
 * @filename: a pointer to filename
 * @text_content: pointer to content of text
 * Return: 0 for success
 */

int create_file(const char *filename, char *text_content)
{
	int op, wr, i;

	i = 0;
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (; text_content[i];)
			i++;
	}

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0000);
	wr = write(op, text_content, i);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);
	return (1);
}
