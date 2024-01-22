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
 * swap_integers - For swapping two integers in an array.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_integers(int *first_int, int *second_int)
{
	int tmp;

	tmp = *first_int;
	*first_int = *second_int;
	*second_int = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence to sort.
 * @sequence: Size of the sequence to sort.
 * @order: Direction to sort in (Up or Down).
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
 * bitonic_sort - Sort an array of integers using the bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Will print the array after each swap, for size = 2^k
 * where k >= 0 (size= powers of 2).
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
