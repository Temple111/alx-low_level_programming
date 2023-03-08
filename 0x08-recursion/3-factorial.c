#include "main.h"

/**
 * factorial - to return the factorial of a number
 * @n: numbers factorial to be found
 * Return: always success
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n <= 1)
		return (1);

	return (n * factorial(n - 1));
}
