#include "sort.h"

/**
 * heap_sort - Implements the sift-down Heap sort algorithm
 * to sort an array of integers in ascending order
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int itr;

	if (array == NULL || size < 2)
		return;

	for (itr = (size / 2) - 1; itr >= 0; itr--)
		maintain_heap_property(array, size, size, itr);

	for (itr = size - 1; itr > 0; itr--)
	{
		integer_swap(array, array + itr);
		print_array(array, size);
		maintain_heap_property(array, size, itr, 0);
	}
}

/**
 * integer_swap - Swaps two integers in an array.
 * @first_int: Pointer to the first integer.
 * @second_int: Pointer to the second integer.
 */
void integer_swap(int *first_int, int *second_int)
{
	int temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}

/**
 * maintain_heap_property - Maintains the heap property in a binary tree.
 * @array: Array representing a binary tree.
 * @size: Size of the array.
 * @subtree_size: Size of the subtree.
 * @parent_index: Index of the parent node.
 */
void maintain_heap_property(int *array, size_t size, size_t subtree_size,
		size_t parent_index)
{
	size_t left_child, right_child, largest;

	left_child = 2 * parent_index + 1;
	right_child = 2 * parent_index + 2;
	largest = parent_index;

	if (left_child < subtree_size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < subtree_size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != parent_index)
	{
		integer_swap(array + parent_index, array + largest);
		print_array(array, size);
		maintain_heap_property(array, size, subtree_size, largest);
	}
}
