#include "sort.h"

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
		print_array(array, size);
	}
}
