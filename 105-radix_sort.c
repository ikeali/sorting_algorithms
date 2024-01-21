#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum value in an array
 *
 * @array: The array
 * @size: Number of elements in the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort_radix - Sorts an array using counting sort based on
 *                       the significant place (exp)
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current significant place (power of 10)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; ++i)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; --i)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; ++i)
        array[i] = output[i];

    printf("Result [%d]: ", exp);
    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the LSD Radix Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort_radix(array, size, exp);
}

