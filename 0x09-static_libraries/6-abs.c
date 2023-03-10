#include "main.h"

/**
 * _abs - a function that computes the absolute value of an integer
 * Return: Asolute value or zero
 * @c: the number to be computed
 */

int _abs(int c)
{
	int abs_val;

	if (c < 0)
	{
		abs_val = c * -1;
		return (abs_val);
	}
	return (c);
}
