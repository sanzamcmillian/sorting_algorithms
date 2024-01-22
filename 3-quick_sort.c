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
 *lomuto_partition - order a subset of integers according to the lomuto partition partition scheme(last element as pivot)
 *
 *@array: an array of integers
 *@size: the size of the array
 *@left: the starting index of the subset to order
 *@right: the ending index of the subset to order
 *
 *Return: the final partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 *lomuto_sort - implements the quicksort algorithm through recursions
 *
 *@array: an array of integers to sort
 *@size: size of the array
 *@left: the starting index of the partition to order.
 *@right: the ending index of the partitioon to order.
 *
 *Return: void
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 *quick_sort - an algorithm to sort an array in ascending order using qucksort algorithm
 *
 *@array: the array of integers to be sorted
 *@size: the size of the array being sorted
 *
 *Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
