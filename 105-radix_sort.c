#include "sort.h"

/**
 * getMax - Get the maximum value in an array.
 * @array: The array to find the maximum value in.
 * @size: Number of elements in @array.
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
	int max_value = array[0];
	size_t itr;

	for (itr = 1; itr < size; itr++)
	{
		if (array[itr] > max_value)
			max_value = array[itr];
	}
	return (max_value);
}

/**
 * countingSort - Perform counting sort based on significant place value.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 * @exp: The significant place value.
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t itr;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Count occurrences of digits at the current significant place */
	for (itr = 0; itr < size; itr++)
		count[(array[itr] / exp) % 10]++;

	/* Update count[i] to store the position of the next occurrence */
	for (itr = 1; itr < 10; itr++)
		count[itr] += count[itr - 1];

	/* Build the output array */
	for (itr = size - 1; itr < size; itr--)
	{
		output[count[(array[itr] / exp) % 10] - 1] = array[itr];
		count[(array[itr] / exp) % 10]--;
	}

	/* Copy the output array back to the original array */
	for (itr = 0; itr < size; itr++)
		array[itr] = output[itr];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, exp;

	if (array == NULL || size < 2)
		return;

	max_value = getMax(array, size);

	for (exp = 1; max_value / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}
