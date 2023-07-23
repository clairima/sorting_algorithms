#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (current != NULL)
	{
		listint_t *temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
		if (current->next != NULL)
			current->next->prev = temp;
		temp->next = current->next;
		current->next = temp;
		current->prev = temp->prev;
		temp->prev = current;

		if (current->prev != NULL)
			current->prev->next = current;
		else
			*list = current;

		temp = current->prev;
		print_list(*list);
		}

		current = current->next;
	}
}
