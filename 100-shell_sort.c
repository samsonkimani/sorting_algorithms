#include "sort.h"

/**
 * shell_sort - the shell sort function
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int inner, outer;
	int valuetoinsert;
	int interval = 1;
	int i = 0;

	while (interval <= (int) size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < (int) size; outer++)
		{
			valuetoinsert = array[outer];
			inner = outer;

			while ((outer > interval - 1) && array[inner - interval] >= valuetoinsert)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}

			array[inner] = valuetoinsert;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
		i++;
	}
}
