#include "sort.h"

/**
 * max_value - Finds the maximum value in an array
 *
 * @array: The array
 * @size: Number of elements in @array
 *
 * Return: The maximum value
 */
int max_value(int *array, size_t size)
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
 * setup_count_array - Initializes and sets up the counting array
 *
 * @count: The counting array
 * @max: The maximum value in the array
 */
void setup_count_array(int *count, int max)
{
    int i;

    for (i = 0; i <= max; ++i)
        count[i] = 0;

    print_array(count, max + 1);
}

/**
 * cumulative_count - Computes cumulative count for counting array
 *
 * @count: The counting array
 * @max: The maximum value in the array
 */
void cumulative_count(int *count, int max)
{
    int i;

    for (i = 1; i <= max; ++i)
        count[i] += count[i - 1];
}

/**
 * fill_output_array - Fills the output array using counting array
 *
 * @array: The original array
 * @output: The output array
 * @count: The counting array
 * @size: Number of elements in @array
 */
void fill_output_array(int *array, int *output, int *count, size_t size)
{
    ssize_t i;

    for (i = size - 1; i >= 0; --i)
    {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }
}

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

    max = max_value(array, size);
    count = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));

    if (!count || !output)
    {
        free(count);
        free(output);
        return;
    }

    setup_count_array(count, max);

    for (i = 0; (size_t)i < size; ++i)
        ++count[array[i]];

    cumulative_count(count, max);

    fill_output_array(array, output, count, size);

    for (i = 0; (size_t)i < size; ++i)
        array[i] = output[i];

    free(count);
    free(output);
}

