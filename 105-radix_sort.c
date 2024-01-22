#include "sort.h"

/**
 * getMax - Get the maximum value in an array.
 * @array: The array to find the maximum value in.
 * @size: Number of elements in @array.
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
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
	size_t i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Count occurrences of digits at the current significant place */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Update count[i] to store the position of the next occurrence */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

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
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}
