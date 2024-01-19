#include "sort.h"

/**
 * selection_sort - Function to use selection sorting
 * to sort an array of integers in ascending order
 *
 * @array: The array that needs to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t itr1, itr2, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (itr1 = 0; itr1 < size - 1; itr1++)
	{
		min_idx = itr1;

		for (itr2 = itr1 + 1; itr2 < size; itr2++)
		{
			if (array[itr2] < array[min_idx])
				min_idx = itr2;
		}

		if (min_idx != itr1)
		{
			temp = array[itr1];
			array[itr1] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
