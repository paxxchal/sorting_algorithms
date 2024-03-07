#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order 
 * @list: list to be arranged
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *back;

	while (current != NULL)
	{
		back = current->prev;
		while (current != NULL && back != NULL && ((current->n) < (back->n)))
		{
			if (current->next != NULL)
			{
				(current->next)->prev = back;
			}
			if (back->prev != NULL)
			{
				(back->prev)->next = current;
			}
			current->prev = back->prev;
			back->next = current ->next;
			current->next = back;
			if (back->prev == NULL)
			{
				*list = current;
			}
			back->prev = current;
			back = current->prev;
			print_list(*list);
		}
		current = current ->next;
	}
}
