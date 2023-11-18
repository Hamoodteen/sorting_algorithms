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
/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}