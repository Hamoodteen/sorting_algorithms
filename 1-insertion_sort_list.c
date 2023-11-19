#include "sort.h"

/**
 * insertion_sort_list - f
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr = *list;
	listint_t *temp, *prev, *ptr;

	while (curr != NULL)
	{
		temp = curr->next;
		prev = NULL;
		ptr = sorted;
		while ((ptr != NULL) && (ptr->n <= curr->n))
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (prev == NULL)
		{
			curr->prev = NULL;
			sorted = curr;
		}
		else
		{
			prev->next = curr;
			curr->prev = prev;
		}
		curr->next = ptr;
		if (ptr != NULL)
			ptr->prev = curr;
		curr = temp;
	}
	*list = sorted;
}
