#include "sort.h"

/**
 * swap_ints - Function to swap the values of two integers in an array
 * @first_int: The first integer to swap.
 * @second_int: The second integer to swap.
 *
 */
void swap_ints(int *first_int, int *second_int)
{
	int tmp;

	tmp = *first_int;
	*first_int = *second_int;
	*second_int = tmp;
}

/**
 * lomuto_partition - Function that implements the Lomuto partition scheme for
 * quicksort, ordering a subset of an array of integers.
 * @array: The array of integers to partition.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot;
	int above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Function to implement the quicksort algorithm by recursion,
 * using the Lomuto partition scheme for ordering an array of integers.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Function to sort an array of integers in ascending order
 * using the quicksort algorithm with the Lomuto partition scheme.
 * It prints the array after each swap of two elements.
 * ascending order using the quicksort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
