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
 * bubble_sort - f
 * @array: int
 * @size: size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2)
	{
		print_array(array, size);
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		if (&array[i] > &array[i + 1])
			swapint(&array[i], &array[i + 1]);
		print_array(array, size);
	}
}
