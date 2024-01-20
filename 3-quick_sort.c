#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @size: Size of the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot, i, j;

	pivot = array[right];
	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}

	swap_ints(&array[i + 1], &array[right]);
	if (i + 1 != right)
		print_array(array, size);

	return (i + 1);
}

/**
 * lomuto_sort - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (left < right)
	{
		partition_index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, right);
	}
}

/**
 * quick_sort - Function to sort an array using Quick Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
