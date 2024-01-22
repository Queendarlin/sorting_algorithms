#include "deck.h"

/**
 * compare_strings - Compare two strings.
 * @string1: The first string.
 * @string2: The second string.
 *
 * Return: + if str1 > str2, 0 if str1 == str2, - if str1 < str2.
 */
int compare_strings(const char *string1, const char *string2)
{
	while (*string1 && *string2 && *string1 == *string2)
	{
		string1++;
		string2++;
	}

	if (*string1 != *string2)
		return (*string1 - *string2);
	return (0);
}

/**
 * get_card_value - To get the card value
 * @card: Pointer to a deck card.
 *
 * Return: Numerical value of the deck card.
 */
char get_card_value(deck_node_t *card)
{
	if (compare_strings(card->card->value, "Ace") == 0)
		return (0);
	if (compare_strings(card->card->value, "1") == 0)
		return (1);
	if (compare_strings(card->card->value, "2") == 0)
		return (2);
	if (compare_strings(card->card->value, "3") == 0)
		return (3);
	if (compare_strings(card->card->value, "4") == 0)
		return (4);
	if (compare_strings(card->card->value, "5") == 0)
		return (5);
	if (compare_strings(card->card->value, "6") == 0)
		return (6);
	if (compare_strings(card->card->value, "7") == 0)
		return (7);
	if (compare_strings(card->card->value, "8") == 0)
		return (8);
	if (compare_strings(card->card->value, "9") == 0)
		return (9);
	if (compare_strings(card->card->value, "10") == 0)
		return (10);
	if (compare_strings(card->card->value, "Jack") == 0)
		return (11);
	if (compare_strings(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_by_kind - Sort a deck of cards by suit.
 * @deck: Pointer to the head of a deck_node_t list.
 */
void sort_deck_by_kind(deck_node_t **deck)
{
	deck_node_t *current, *insert, *temp_ptr;

	for (current = (*deck)->next; current != NULL; current = temp_ptr)
	{
		temp_ptr = current->next;
		insert = current->prev;
		while (insert != NULL && insert->card->kind > current->card->kind)
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck_by_value - Sort a deck of cards by value within each suit.
 * @deck: Pointer to the head of a deck_node_t list.
 */
void sort_deck_by_value(deck_node_t **deck)
{
	deck_node_t *current, *insert, *temp_ptr;

	for (current = (*deck)->next; current != NULL; current = temp_ptr)
	{
		temp_ptr = current->next;
		insert = current->prev;
		while (insert != NULL &&
				insert->card->kind == current->card->kind &&
				get_card_value(insert) > get_card_value(current))
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards by suit and value.
 * @deck: Pointer to the head of a deck_node_t list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_by_kind(deck);
	sort_deck_by_value(deck);
}
