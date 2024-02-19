#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array;
	int max_value = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create and initialize the counting array */
	count_array = calloc((size_t)(max_value + 1), sizeof(int));
	if (count_array == NULL)
		return;

	/* Count occurrences of each element */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Adjust the counts to rep positions in the sorted array */
	for (i = 1; i <= (size_t)max_value; i++)
		count_array[i] += count_array[i - 1];

	/* Create the sorted array */
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = size - 1; i < size; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted array back to the origl array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Print the counting array */
	printf("Counting array:\n");
	print_array(count_array, max_value + 1);

	/* Free allocated memory */
	free(count_array);
	free(sorted_array);
}
