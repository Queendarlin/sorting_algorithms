#include "sort.h"

/**
 * heapify - Helper function to build a max heap from an array.
 *
 * @array: Array to be transformed into a max heap.
 * @size: Size of the array.
 * @index: Index to start heapifying from.
 */
void heapify(int *array, size_t size, size_t index);

/**
 * swap - Helper function to swap two elements in an array.
 *
 * @a: First element.
 * @b: Second element.
 */
void swap(int *a, int *b);

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm.
 *
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the sift-down Heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}

/**
 * heapify - Helper function to build a max heap from an array.
 *
 * @array: Array to be transformed into a max heap.
 * @size: Size of the array.
 * @index: Index to start heapifying from.
 */
void heapify(int *array, size_t size, size_t index)
{
	size_t largest, left, right;

	largest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * swap - Helper function to swap two elements in an array.
 *
 * @a: First element.
 * @b: Second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
