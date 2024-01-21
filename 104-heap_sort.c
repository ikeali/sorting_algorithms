#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation in a heap
 *
 * @array: The array to be sorted
 * @size: Size of the heap
 * @index: The index of the root of the heap
 * @max_size: Maximum size of the array
 */
	void sift_down(int *array, size_t size, size_t index, size_t max_size)
	{
	size_t root = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;
	size_t largest = root;

	if (left_child < size && array[left_child] > array[largest])
	largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
	largest = right_child;

	if (largest != root)
	{
	int temp = array[root];

	array[root] = array[largest];
	array[largest] = temp;

	print_array(array, max_size);

	sift_down(array, size, largest, max_size);
	}
	}

/**
 * heapify - Builds a heap from an array
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
	void heapify(int *array, size_t size)
	{
	ssize_t i;

	for (i = size / 2 - 1; i >= 0; --i)
	sift_down(array, size, (size_t)i, size);
	}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *              the Heap Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
	void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (!array || size < 2)
	return;

	heapify(array, size);

	for (i = size - 1; i > 0; --i)
	{
	int temp = array[0];

	array[0] = array[i];
	array[i] = temp;

	print_array(array, size);

	sift_down(array, (size_t)i, 0, size);
	}
	}

