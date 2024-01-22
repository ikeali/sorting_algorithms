#include "sort.h"

/**
 * hoare_partition - Implements the Hoare partition scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element after partition
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low - 1;
    j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        print_array(array, size);
    }
}

/**
 * quick_sort_recursive_hoare - Recursive function for the Quick Sort algorithm
 *                               using the Hoare partition scheme
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 */
void quick_sort_recursive_hoare(int *array, size_t low, size_t high, size_t size)
{
    size_t pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);

        quick_sort_recursive_hoare(array, low, pivot, size);
        quick_sort_recursive_hoare(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick Sort algorithm (Hoare partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array && size > 1)
    {
        quick_sort_recursive_hoare(array, 0, size - 1, size);
    }
}

