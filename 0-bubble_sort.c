#include "sort.h"

/**
 * swapint0 - f
 * @a: a
 * @b: b
*/
void swapint0(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - f
 * @array: int
 * @size: size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if ((array == NULL) || (size == 0))
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapint0(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
