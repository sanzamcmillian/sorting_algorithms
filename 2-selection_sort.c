#include "sort.h"

/**
 *swap_ints - swaps two integers in an array
 *
 *@a: the first integer to swap
 *@b: the second integer to swap
 *
 *Return: void
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *selection_sort - an algorithm to sort an array of integers in selectionsor
 *
 *@array: array to be sorted
 *@size: the size of the array
 *
 *Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
