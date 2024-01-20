#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_value, itr;

	if (size <= 0)
		return (0);

	for (max_value = array[0], itr = 1; itr < size; itr++)
	{
		if (array[itr] > max_value)
			max_value = array[itr];
	}

	return (max_value);
}

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, max_value, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	max_value = get_max(array, size);
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;

	print_array(count_array, max_value + 1);

	for (i = 1; i < (max_value + 1); i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count_array);
}
