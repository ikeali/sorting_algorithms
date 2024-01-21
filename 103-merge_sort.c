#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into one sorted array
 *
 * @array: The original array
 * @left: The left sub-array
 * @left_size: Size of the left sub-array
 * @right: The right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *merged;

    merged = malloc((left_size + right_size) * sizeof(int));
    if (!merged)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];

    while (j < right_size)
        merged[k++] = right[j++];

    for (i = 0, k = 0; i < left_size + right_size; ++i, ++k)
        array[i] = merged[k];

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(merged);
}

/**
 * merge_sort_recursive - Recursive function for the top-down merge sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort_recursive(int *array, size_t size)
{
    size_t mid = size / 2;
    int *left, *right;

    if (size < 2)
        return;

    left = array;
    right = array + mid;

    printf("[left]: ");
    print_array(left, mid);
    printf("[right]: ");
    print_array(right, size - mid);

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);

    merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm (top-down)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (array && size > 1)
    {
        merge_sort_recursive(array, size);
        printf("[Done]: ");
        print_array(array, size);
    }
}

