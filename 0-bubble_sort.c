#include "sort.h"

/**
 * bubble_sort - The function to use bubble sorting to sort
 * an array of inteers in ascending order
 * @array: The array that needs to be sorted
 * @size: The number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t itr_sort, itr_unsort;
	int temp;
	int swap_check;

	if (array == NULL || size < 2)
		return;

	for (itr_sort = 0; itr_sort < size - 1; itr_sort++)
	{
		swap_check = 0;
		for (itr_unsort = 0; itr_unsort < size - itr_sort - 1; itr_unsort++)
		{
			if (array[itr_unsort] > array[itr_unsort + 1])
			{
				temp = array[itr_unsort];
				array[itr_unsort] = array[itr_unsort + 1];
				array[itr_unsort + 1] = temp;
				swap_check = 1;

				print_array(array, size);
			}
		}
		if (swap_check == 0)
			break;
	}
}
