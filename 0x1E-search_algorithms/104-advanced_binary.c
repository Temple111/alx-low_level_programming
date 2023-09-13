#include "search_algos.h"

/**
 * _search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int _search(int *array, size_t size, int value)
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
	{
		if (m > 0)
			return (_search(array, m + 1, value));
		return ((int)m);
	}

	if (value < array[m])
		return (_search(array, m + 1, value));

	m++;
	return (_search(array + m, size - m, value) + m);
}

/**
 * advanced_binary - calls to rec_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int idx;

	idx = _search(array, size, value);

	if (idx >= 0 && array[idx] != value)
		return (-1);

	return (idx);
}
