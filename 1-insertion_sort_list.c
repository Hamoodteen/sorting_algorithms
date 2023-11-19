#include "sort.h"

/**
 * insertion_sort_list - f
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *temp, *prev, *ptr;

	while (current != NULL)
	{
		temp = current->next;
		prev = NULL;
		ptr = sorted;
		while ((ptr != NULL) && (ptr->n <= current->n))
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (prev == NULL)
		{
			current->prev = NULL;
			sorted = current;
		}
		else
		{
			prev->next = current;
			current->prev = prev;
		}
		current->next = ptr;
		if (ptr != NULL)
			ptr->prev = current;
		current = temp;
	}
	*list = sorted;
}
