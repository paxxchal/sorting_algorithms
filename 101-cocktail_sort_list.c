#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Cocktail shaker sort of a doublely linked list
 * @list: list to be sorted
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *back;
	listint_t *next1 = current -> next;
	listint_t *next2 = *list;

	while (next2 -> next != NULL)
	{
		while (current != NULL && next1 != NULL)
		{
			if ((current -> n) > (next1->n))
			{
				if (next1->next != NULL)
				{
					(next1->next)->prev = current;
				}
				if (current->prev != NULL)
				{
					(current->prev)->next = next1;
				}
				next1->prev = current->prev;
				current->next = next1 ->next;
				next1->next = current;
				if (current->prev == NULL)
				{
					*list = next1;
				}
				current->prev = next1;
				print_list(*list);
			}
			else
			{
				current = current -> next;
			}
			next1 = current->next;
		}
		current = current->prev;
		back = current -> prev;
		while (current != NULL && current -> prev != NULL)
		{
			back = current -> prev;
			if ((current->n) < (back->n))
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
				print_list(*list);
			}
			else
			{
				current = current -> prev;
			}
		}
		next2 = next2 -> next;
		current = next2;
		next1 = current ->next;
	}
}
