#include "sort.h"

/**
 * swap_integers - For swapping two integers in an array.
 *
 * @first_int: Pointer to the first integer to swap.
 * @second_int: Pointer to the second integer to swap.
 */
void swap_integers(int *first_int, int *second_int)
{
	int tmp;

	tmp = *first_int;
	*first_int = *second_int;
	*second_int = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the subset to order.
 * @end: Ending index of the subset to order.
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, high, low;

	pivot = array + end;
	for (high = low = start; low < end; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_integers(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_integers(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * lomuto_quick_sort - Recursive quicksort using Lomuto partition.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @start: Starting index of the array partition to order.
 * @end: Ending index of the array partition to order.
 */
void lomuto_quick_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		lomuto_quick_sort(array, size, start, part - 1);
		lomuto_quick_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers using quicksort.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, size, 0, size - 1);
}
