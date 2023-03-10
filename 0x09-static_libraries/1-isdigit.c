#include <stdio.h>

/**
 * _isdigit - checks if a character is a digit
 * @x: the number to be checked
 * Return: 1 for the character or 0 for for anything else
 */

int _isdigit(int x)
{
	if (x >= 48 && x <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}
