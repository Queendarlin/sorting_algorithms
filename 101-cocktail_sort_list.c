#include "sort.h"

/**
 * swap_ahead - Swap a node in a listint_t doubly-linked
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current_node: A pointer to the current node of the cocktail shaker
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **current_node)
{
	listint_t *tmp = (*current_node)->next;

	if ((*current_node)->prev != NULL)
		(*current_node)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current_node)->prev;
	(*current_node)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current_node;
	else
		*tail = *current_node;
	(*current_node)->prev = tmp;
	tmp->next = *current_node;
	*current_node = tmp;
}

/**
 * swap_behind - Swap a node in a listint_t
 * doubly-linked list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current_node: A pointer to the current node of the cocktail shaker
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **current_node)
{
	listint_t *tmp = (*current_node)->prev;

	if ((*current_node)->next != NULL)
		(*current_node)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*current_node)->next;
	(*current_node)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current_node;
	else
		*list = *current_node;
	(*current_node)->next = tmp;
	tmp->prev = *current_node;
	*current_node = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of
 * integers in ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current_node;
	bool not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (not_stirred == false)
	{
		not_stirred = true;
		for (current_node = *list; current_node != tail;
				current_node = current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				swap_ahead(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
		for (current_node = current_node->prev; current_node != *list;
				current_node = current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_behind(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
	}
}
