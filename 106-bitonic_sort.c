#include "sort.h"

#define U 0
#define D 1

void swap_integers(int *first_int, int *second_int);
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char order);
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence,
		char order);
void bitonic_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers in an array.
 * @first_int: The first integer to swap.
 * @second_int: The second integer to swap.
 */
void swap_integers(int *first_int, int *second_int)
{
	int tmp;

	tmp = *first_int;
	*first_int = *second_int;
	*second_int = tmp;
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
	size_t itr, jumps = sequence / 2;

	if (sequence > 1)
	{
		for (itr = start; itr < start + jumps; itr++)
		{
			if ((order == U && array[itr] > array[itr + jumps]) ||
					(order == D && array[itr] <
					 array[itr + jumps]))
			{
				swap_integers(array + itr,
						array + itr + jumps);
			}
		}
		bitonic_merge(array, size, start, jumps, order);
		bitonic_merge(array, size, start + jumps, jumps, order);
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
	char *string = (order == U) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, string);
		print_array(array + start, sequence);

		bitonic_sequence(array, size, start, cut, U);
		bitonic_sequence(array, size, start + cut, cut, D);
		bitonic_merge(array, size, start, sequence, order);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, string);
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
