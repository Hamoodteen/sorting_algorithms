#include "sort.h"

void swapint(int *a, int *b);

/**
 * selection_sort - f
 * @array: arr
 * @size: size
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, mini;

	if ((array == NULL) || (size == 0))
		return;
	for (i = 0; i < size - 1; i++)
	{
		mini = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mini])
			{
				mini = j;
			}
		}
		if (mini != i)
		{
			swapint(&array[i], &array[mini]);
			print_array(array, size);
		}
	}
}
