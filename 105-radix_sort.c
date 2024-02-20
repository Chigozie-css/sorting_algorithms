#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum element from an array
 * @array: Array to find the maximum from
 * @size: Size of the array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Perform counting sort on an array based on a specific digit
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent indicating the current digit to consider
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order using Radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
