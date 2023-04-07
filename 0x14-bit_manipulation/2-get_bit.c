#include "main.h"
#include <stdio.h>

/**
 * get_bit - returns the value of a bit at agiven index
 * @index: is index of bit we to find and it starts from 0
 * @n: the bit
 * Return: value of the bit at index or -1 if error occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (8 * sizeof(unsigned long int)))
		return (-1);
	if ((n & (1 << index)) == 0)
		return (0);
	else
		return (1);
}
