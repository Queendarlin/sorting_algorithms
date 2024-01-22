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
 * hoare_partition - Perform Hoare partition for quicksort.
 * @array: The array to partition.
 * @size: The size of the array.
 * @start: Starting index of the partition.
 * @end: Ending index of the partition.
 *
 * Return: Last partition index.
 *
 * Using last partition element as the pivot.
 * To print array after swaping two elements.
 */
int hoare_partition(int *array, size_t size, int start, int end)
{
	int pivot_point = array[end];
	int above_p, below_p;

	for (above_p = start - 1, below_p = end + 1; above_p < below_p;)
	{
		do {
			above_p++;
		} while (array[above_p] < pivot_point);

		do {
			below_p--;
		} while (array[below_p] > pivot_point);

		if (above_p < below_p)
		{
			swap_integers(array + above_p, array + below_p);
			print_array(array, size);
		}
	}

	return (above_p);
}

/**
 * hoare_quicksort - Implement quicksort using the Hoare partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: Starting index of the array
 * @end: Ending index of the array
 */
void hoare_quicksort(int *array, size_t size, int start, int end)
{
	int partition_index;

	if (end - start > 0)
	{
		partition_index = hoare_partition(array, size, start, end);
		hoare_quicksort(array, size, start, partition_index - 1);
		hoare_quicksort(array, size, partition_index, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers using quicksort (Hoare scheme).
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Using the Hoare partition scheme.
 * To print an array after swapping two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quicksort(array, size, 0, size - 1);
}
