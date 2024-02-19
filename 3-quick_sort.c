#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursively sorts an array of integers using
 *                       the Quick sort algorithm with Lomuto partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */

void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high);

		printf("\n");
		print_array(array, high - low + 1);

		quicksort_recursive(array, low, pi - 1);
		quicksort_recursive(array, pi + 1, high);
	}
}

/**
 * lomuto_partition - Partitions an array of integers using
 *                    the Lomuto partition scheme for Quick sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	return (i + 1);
}
