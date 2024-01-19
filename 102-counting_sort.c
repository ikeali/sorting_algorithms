#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max, i;

    if (!array || size < 2)
        return;

    max = array[0];
    for (i = 1; i < (int)size; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;

    output = malloc(size * sizeof(int));
    if (!output)
    {
        free(count);
        return;
    }

    for (i = 0; i <= max; ++i)
        count[i] = 0;

    for (i = 0; (size_t)i < size; ++i)
        ++count[array[i]];

    print_array(count, max + 1);

    for (i = 1; i <= max; ++i)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; --i)
    {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }

    for (i = 0; (size_t)i < size; ++i)
        array[i] = output[i];

    free(count);
    free(output);
}

