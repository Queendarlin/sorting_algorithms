#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * algorithm with the Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, itr1, itr2;
	int temp;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (itr1 = gap; itr1 < size; itr1++)
		{
			temp = array[itr1];
			itr2 = itr1;

			while (itr2 >= gap && array[itr2 - gap] > temp)
			{
				array[itr2] = array[itr2 - gap];
				itr2 -= gap;
			}

			array[itr2] = temp;
		}

		gap /= 3;

		print_array(array, size);
	}
}
