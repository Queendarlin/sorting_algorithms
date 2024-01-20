#include "sort.h"

/**
 * get_max - Find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_val, itr;

	/* Initialize max_val with the first element */
	for (max_val = array[0], itr = 1; itr < size; itr++)
	{
		/* Update max_val if a larger element is found */
		if (array[itr] > max_val)
			max_val = array[itr];
	}

	return (max_val);
}

/**
 * counting_sort - Sort an array of integers using Counting sort.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void counting_sort(int *array, size_t size)
{
	int *array_count, *array_sorted, max_val, itr;

	if (array == NULL || size < 2)
		return;

	array_sorted = malloc(sizeof(int) * size);
	if (array_sorted == NULL)
		return;

	/* Find the maximum value in the array */
	max_val = get_max(array, size);

	/* Allocate memory for the counting array */
	array_count = malloc(sizeof(int) * (max_val + 1));
	if (array_count == NULL)
	{
		free(array_sorted);
		return;
	}
	for (itr = 0; itr < (max_val + 1); itr++)
		array_count[itr] = 0;

	for (itr = 0; itr < (int)size; itr++)
		array_count[array[itr]] += 1;

	for (itr = 1; itr < (max_val + 1); itr++)
		array_count[itr] += array_count[itr - 1];

	print_array(array_count, max_val + 1);

	for (itr = 0; itr < (int)size; itr++)
	{
		array_sorted[array_count[array[itr]] - 1] = array[itr];
		array_count[array[itr]] -= 1;
	}
	for (itr = 0; itr < (int)size; itr++)
		array[itr] = array_sorted[itr];

	free(array_sorted);
	free(array_count);
}
