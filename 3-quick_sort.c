#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using Quick sort (Lomuto partition).
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function
 * for Quick sort using Lomuto partition.
 * @array: Pointer to the first element of the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, low, high);

		quicksort_recursive(array, low, pivot_idx - 1);
		quicksort_recursive(array, pivot_idx + 1, high);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: Pointer to the first element of the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 *
 * Return: The final index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

