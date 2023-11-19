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
	listint_t *next, *temp;

	while (current != NULL)
	{
		next = current->next;
		if ((sorted == NULL) || (sorted->n >= current->n))
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			temp = sorted;
			while ((temp->next != NULL) && (temp->next->n < current->n))
				temp = temp->next;
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	*list = sorted;
}
