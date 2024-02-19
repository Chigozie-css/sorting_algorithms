#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays in sorted order
 * @array: Pointer to the original array
 * @temp_array: Pointer to the temporary array for merging
 * @left: Pointer to the start of the left subarray
 * @middle: Pointer to the middle of the subarrays
 * @right: Pointer to the end of the right subarray
 */
void merge(int *array, int *temp_array,
		size_t left, size_t middle, size_t right)
{
	size_t i, j, k;

	printf("[Merging...]\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	/* Merge the two subarrays into temp_array */
	for (i = left, j = middle, k = 0; i < middle && j < right; k++)
	{
		if (array[i] <= array[j])
			temp_array[k] = array[i++];
		else
			temp_array[k] = array[j++];
	}

	while (i < middle)
		temp_array[k++] = array[i++];
	while (j < right)
		temp_array[k++] = array[j++];

	/* Copy the sorted elements from temp_array back to array */
	for (i = 0, k = left; k < right;)
		array[k++] = temp_array[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive function to perform Merge sort
 * @array: Pointer to the array to be sorted
 * @temp_array: Pointer to the temporary array for merging
 * @left: Pointer to the start of the subarray
 * @right: Pointer to the end of the subarray
 */
void merge_sort_recursive(int *array,
		int *temp_array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = left + (right - left) / 2;

		merge_sort_recursive(array, temp_array, left, middle);
		merge_sort_recursive(array, temp_array, middle, right);
		merge(array, temp_array, left, middle, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *               using the Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;

	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	merge_sort_recursive(array, temp_array, 0, size);

	free(temp_array);
}
