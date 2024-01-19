#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; ++j)
    {
        if (array[j] <= pivot)
        {
            ++i;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);

        if (pivot > 0)
            quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quick_sort_recursive(array, 0, size - 1, size);
}

