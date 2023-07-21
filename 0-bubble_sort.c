#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * swap - Swaps two integer values.
 *
 * @a: Pointer to the first integer value.
 * @b: Pointer to the second integer value.
 *
 * Description: This function swaps the values of two integers using pointers.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: This function sorts
 * the elements of the array using the Bubble sort
 *              algorithm in ascending order.
 */
void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
	{
		return;
	}

	for (size_t i = 0; i < size - 1; i++)
	{
		int swapped = 0;

		for (size_t j = 0; j < size - i - 1; j++)
		{
			for (size_t k = 0; k < size; k++)
			{
				printf("%d, ", array[k]);
			}
			printf("\n");
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}

		if (!swapped)
		{
			break;
		}

	}
}
