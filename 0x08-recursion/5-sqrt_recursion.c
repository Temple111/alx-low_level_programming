#include "main.h"

/**
 * _sqrt_recursion - calculate the square root of a number
 * @n: integers squareroot to be found
 * Return: always success
 */

int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 * square - find square root
 * @n: int to find square root
 * @val: square root
 * Return: always success
 */

int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);
}
