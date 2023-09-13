#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of
 * integers using the Linear search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int a;

	if (array == NULL)
		return (-1);

	for (a = 0; a < (int)size; a++)
	{
		printf("Value checked array[%u] = [%d]\n", a, array[a]);
		if (value == array[a])
			return (a);
	}
	return (-1);
}
