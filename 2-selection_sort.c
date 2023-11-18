#include "sort.h"

/**
 * swapint2 - f
 * @a: a
 * @b: b
*/
void swapint2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
			swapint2(&array[i], &array[mini]);
			print_array(array, size);
		}
	}
}
