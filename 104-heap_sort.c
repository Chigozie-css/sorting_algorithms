#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Perform sift-down operation on a binary tree
 * @array: Array representing the binary tree
 * @size: Size of the array
 * @index: Index of the node to start the sift-down operation
 * @max_size: Maximum size of the heap
 */

void sift_down(int *array, size_t size,
		size_t index, size_t max_size)
{
	size_t left, right, largest, temp;

	while (index < max_size)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;
		largest = index;

		if (left < size && array[left] > array[largest])
			largest = left;

		if (right < size && array[right] > array[largest])
			largest = right;

		if (largest != index)
		{
			temp = array[index];
			array[index] = array[largest];
			array[largest] = temp;
			print_array(array, max_size);
			index = largest;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
