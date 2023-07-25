#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending
 * order using Shell sort with Knuth sequence.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

    /* Calculate the initial gap based on Knuth sequence */
	int gap = 1;

	while (gap < (int)size)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

    /* Perform Shell sort with Knuth sequence */
	while (gap > 0)
	{
		for (int i = gap; i < (int)size; i++)
		{
			int temp = array[i];
			int j = i;

			while (j >= gap && array[j - gap] > temp)
			{
			array[j] = array[j - gap];
			j -= gap;
			}

			array[j] = temp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
