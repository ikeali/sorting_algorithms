#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order using
 *                      the Cocktail Shaker Sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
	void cocktail_sort_list(listint_t **list)
	{
	listint_t *current;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
	return;

	while (swapped)
	{
	swapped = 0;
	for (current = *list; current->next != NULL; current = current->next)
	{
	if (current->n > current->next->n)
	{
	if (current->prev)
	current->prev->next = current->next;
	else
	*list = current->next;

	current->next->prev = current->prev;
	current->prev = current->next;
	current->next = current->next->next;

	if (current->next)
	current->next->prev = current;

	current->prev->next = current;
	print_list(*list);
	swapped = 1;
	}
	}

	if (!swapped)
	break;

	swapped = 0;
	for (; current->prev != NULL; current = current->prev)
	{
	if (current->n < current->prev->n)
	{
	if (current->next)
	current->next->prev = current->prev;

	current->prev->next = current->next;
	current->next = current->prev;
	current->prev = current->prev->prev;

	if (current->prev)
	current->prev->next = current;
	else
	*list = current;

	print_list(*list);
	swapped = 1;
	}
	}
	}
	}

