#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: bit to be set
 * @index: index of bit to be set starting from 0
 * Return: 1 for success or -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	*n &= ~(1 << index);
	if (index >= (8 * sizeof(unsigned long int)))
		return (-1);
	else
		return (1);
}
