#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: bit to be set
 * @index: index of the bit you want to set starting from 0
 * Return: 1 if successful or -1 if not successful
 */
int set_bit(unsigned long int *n, unsigned int index)
{

	if (index >= (sizeof(unsigned long int)* 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
