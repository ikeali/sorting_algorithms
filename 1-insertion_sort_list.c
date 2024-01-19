#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                        the Insertion Sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
	void insertion_sort_list(listint_t **list)
	{
	listint_t *current, *temp;

	if (!list || !(*list) || !(*list)->next)
	return;

	current = (*list)->next;

	while (current)
	{
	temp = current->next;

	while (current->prev && current->n < current->prev->n)
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
	}

	current = temp;
	}
	}

