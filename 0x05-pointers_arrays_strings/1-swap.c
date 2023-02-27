#include <stdio.h>

/**
 * swap_int - swaps the value of two integers
 * @a: the first integer
 * @b: the second integer
 * return: nothing
 */

void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
