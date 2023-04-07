#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: is a pointer to a string of 0 and 1 chars
 * Return: the converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int index = 0;
	unsigned int num = 0;

	if (!b)
		return (0);
	for (; b[index]; index++)
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);

		num = 2 * num + (b[index] - '0');
	}
	return (num);
}
