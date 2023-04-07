#include "main.h"
/**
 * get_endianness - checks the endianness
 * Return: 0 if a big endian or 1 if little endian
 */
int get_endianness(void)
{
	int n;
	char *b;

	b = (char *)&n;
	n = 1;

	if (*b == 1)
		return (1);
	else
		return (0);
}
