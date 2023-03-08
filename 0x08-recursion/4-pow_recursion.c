#include "main.h"

/**
 * _pow_recursion - calculate the root of a number.
 * @x: the numbers root to be found
 * @y: the number to raised to
 * Return: always success
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}
