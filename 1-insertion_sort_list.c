#include "sort.h"

/**
 * insertion_sort_list - Function to use insertion sorting
 * to sort a doubly linked link in ascending order
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_ptr, *temp_ptr;

	current_ptr = (*list)->next;

	while (current_ptr->next != NULL)
	{
		temp_ptr = current_ptr;
		while (temp_ptr->prev != NULL && temp_ptr->n < temp_ptr->prev->n)
		{
			temp_ptr->prev->next = temp_ptr->next;

			if (temp_ptr->next != NULL)
				temp_ptr->next->prev = temp_ptr->prev;

			temp_ptr->next = temp_ptr->prev;
			temp_ptr->prev = temp_ptr->prev->prev;

			if (temp_ptr->prev != NULL)
				temp_ptr->prev->next = temp_ptr;

			else
				*list = temp_ptr;

			temp_ptr->next->prev = temp_ptr;

			print_list(*list);
		}

		current_ptr = current_ptr->next;
	}
}
