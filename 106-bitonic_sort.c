#include "sort.h"

#define U 0
#define D 1

void swap_integers(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char order);
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence,
		char order);
void bitonic_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @order: The direction to sort in (U or D).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char order)
{
	size_t i, jump = sequence / 2;

	if (sequence > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((order == U && array[i] > array[i + jump]) ||
					(order == D && array[i] < array[i + jump]))
			{
				swap_integers(array + i, array + i + jump);
			}
		}
		bitonic_merge(array, size, start, jump, order);
		bitonic_merge(array, size, start + jump, jump, order);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sequence: The size of a block of the building bitonic sequence.
 * @order: The direction to sort the bitonic sequence block in (U or D).
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence,
		char order)
{
	size_t cut = sequence / 2;

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%c):\n", sequence, size, order ? 'D' : 'U');
		print_array(array + start, sequence);

		bitonic_sequence(array, size, start, cut, U);
		bitonic_sequence(array, size, start + cut, cut, D);
		bitonic_merge(array, size, start, sequence, order);

		printf("Result [%lu/%lu] (%c):\n", sequence, size, order ? 'D' : 'U');
		print_array(array + start, sequence);
	}
}

/**
 * bitonic_sort - Sort an array of integers in
 * ascending order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, U);
}
