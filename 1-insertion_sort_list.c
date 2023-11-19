#include "sort.h"

/**
 * movehead - f
 * @head: head
 * @move: move
*/
void movehead(listint_t **head, listint_t *move)
{
	if ((move == NULL) || ((*head) == move))
		return;
	if (move->prev != NULL)
		move->prev->next = move->next;
	if (move->next != NULL)
		move->next->prev = move->prev;
	move->next = (*head);
	move->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = move;
	(*head) = move;
}

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
