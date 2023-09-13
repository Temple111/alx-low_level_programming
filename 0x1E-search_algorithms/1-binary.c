#include "search_algos.h"

/**
 * search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int search(int *array, size_t size, int value)
{
	size_t m = size / 2;
	size_t z;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (z = 0; z < size; z++)
		printf("%s %d", (z == 0) ? ":" : ",", array[z]);

	printf("\n");

	if (m && size % 2 == 0)
		m--;

	if (value == array[m])

		return ((int)m);

	if (value < array[m])
		return (search(array, m, value));
	m++;

	return (search(array + m, size - m, value) + m);
}

/**
 * binary_search - calls to binary_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
