#include "sort.h"

/**
 * quick_sort - quick sort algorithm using lomuto
 * @array: the array to sort
 * @size: the size of the array
 * Return: a sorted array
 */


void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, size, 0, size - 1);
}

/**
 * recursive_quick_sort - recursive function
 * @array: the array to sort
 * @size: the size of the array
 * @start: the starting index
 * @end: the end of the array
 *
 * Return: nothing
 */

void recursive_quick_sort(int *array, size_t size, int start, int end)
{
	int p;

	if (start < end)
	{
		p = partition(array, size, start, end);

		recursive_quick_sort(array, size, start, p - 1);
		recursive_quick_sort(array, size, p + 1, end);
	}
}


/**
 * partition - partition of the array
 * @array: the array to partition
 * @size: the size of the array
 * @start: the start index
 * @end: the end index
 *
 * Return: the partition index
 */

size_t partition(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_int1(array, i, j);
			print_array(array, size);
		}
	}
	swap_int1(array, i + 1, end);
	return (i + 1);
}

/**
 * swap_int1 - a function to swap integers
 * @array: array to use
 * @a: first index
 * @b: the second index
 */

void swap_int1(int *array, int a, int b)
{
	int tmp;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
