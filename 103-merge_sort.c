#include "sort.h"

/**
 * merge_subarr - Sorts a subarray of integers using the merge sort algorithm.
 *
 * @subarr: Subarray of integers to be sorted.
 * @buffer: Temporary buffer to store the sorted subarray.
 * @front: Front index of the subarray.
 * @middle: Middle index of the subarray.
 * @back: Back index of the subarray.
 */
void merge_sub_array(int *subarr, int *buffer, size_t front,
		size_t middle, size_t back)
{
	size_t itr1, itr2, itr3 = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, middle - front);

	printf("[right]: ");
	print_array(subarr + middle, back - middle);

	for (itr1 = front, itr2 = middle; itr1 < middle && itr2 < back; itr3++)
		buffer[itr3] = (subarr[itr1] < subarr[itr2]) ? subarr[itr1++]
			: subarr[itr2++];

	for (; itr1 < middle; itr1++)
		buffer[itr3++] = subarr[itr1];

	for (; itr2 < back; itr2++)
		buffer[itr3++] = subarr[itr2];

	for (itr1 = front, itr3 = 0; itr1 < back; itr1++)
		subarr[itr1] = buffer[itr3++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Recursively implements the merge sort algorithm.
 *
 * @sub_array: Subarray of integers to be sorted.
 * @buffer: Temporary buffer to store the sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */
void merge_sort_recursive(int *sub_array, int *buffer,
		size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(sub_array, buffer, front, middle);
		merge_sort_recursive(sub_array, buffer, middle, back);
		merge_sub_array(sub_array, buffer, front, middle, back);
	}
}

/**
 * merge_sort - Implements the top-down merge sort algorithm for integer array
 *
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
