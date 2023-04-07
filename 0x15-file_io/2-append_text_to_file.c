#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: a pointer to filename
 * @text_content: pointer to content containing text
 * Return: 0 for success
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int op, wr, i;

	i = 0; /* i is length */
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (; text_content[i];)
			i++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(op, text_content, i);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);
	return (1);
}
