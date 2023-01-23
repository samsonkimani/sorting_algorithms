#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */


void selection_sort(int *array, size_t size)
{
	size_t i, minindex, maxindex, left = 0, right = size - 1;
	int swap;

	if (array == NULL)
		return;
	while (left < right)
	{
		minindex = left;
		maxindex = right;
		for (i = left; i <= right; i++)
		{
			if (array[i] < array[minindex])
				minindex = i;
			if (array[i] > array[maxindex])
				maxindex = i;
		}
		if (minindex != left)
		{
			swap = array[left];
			array[left] = array[minindex];
			array[minindex] = swap;
		}

		if (maxindex == left)
			maxindex = minindex;

		if (maxindex != right)
		{
			swap = array[right];
			array[right] = array[maxindex];
			array[maxindex] = swap;
		}
		print_array(array, size);
		left++;
		right--;
	}
}
