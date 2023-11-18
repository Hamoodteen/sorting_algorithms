#include "sort.h"

/**
 * swapint - f
 * @a: a
 * @b: b
*/
void swapint(int *a, int *b)
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
	size_t i, j;
	bool swapped;

	if ((array == NULL) || (size == 0))
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[i] > array[j + 1])
			{
				swapint(&array[i], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
