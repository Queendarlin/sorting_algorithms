#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

int hoare_partition(int *array, size_t size, int start, int end);
void hoare_quicksort(int *array, size_t size, int start, int end);
void swap_integers(int *first_int, int *second_int);
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char order);
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence,
		char order);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void integer_swap(int *first_int, int *second_int);
void maintain_heap_property(int *array, size_t size, size_t subtree_size,
		size_t parent_index);
int get_max(int *array, int size);
void swap_ahead(listint_t **list, listint_t **tail, listint_t **current_node);
void swap_behind(listint_t **list, listint_t **tail, listint_t **current_node);
void cocktail_sort_list(listint_t **list);
void swap_ints(int *first_int, int *second_int);
int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_sort(int *array, size_t size, int start, int end);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
