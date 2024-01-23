#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: first pointer
 * @b: second pointer
*/

void swap_ints(int *a, int *b)
{
	int temp;

	temp  = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of intergers in ascending order
 * @array: pointer to the array
 * @size: size of array
*/

void bubble_sort(int *array, size_t size)

{
	size_t i, t;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (t = 0; t < size - i - 1; t++)
		{
			if (array[t] > array[t + 1])
			{
				swap_ints(&array[t], &array[t + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (swapped == 0)
		{
			break;
		}
	}
}
