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
	listint_t *curr = (*list);

	if ((list == NULL) || (*list == NULL))
		return;
	while (curr != NULL)
	{
		while ((curr->prev != NULL) && (curr->n < curr->prev->n))
			movehead(list, curr->prev);
		print_list((*list));
		curr = curr->next;
	}
}
