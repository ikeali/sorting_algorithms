#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge step of the Bitonic Sort algorithm
 *
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @count: The size of the subarray to be merged
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; ++i)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;

                printf("Merging [%lu/%lu] (%s): ", i, i + k, dir ? "UP" : "DOWN");
                print_array(array, count);
            }
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for the Bitonic Sort algorithm
 *
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @count: The size of the subarray to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array && size > 0 && (size & (size - 1)) == 0)
    {
        bitonic_sort_recursive(array, 0, size, 1);
    }
}

