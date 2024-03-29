#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);

/* Helper functions for merge_sort */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size);
void merge_sort_recursive(int *array, size_t size);
/* Helper functions for heap_sort */
void sift_down(int *array, size_t size, size_t index, size_t max_size);
void heapify(int *array, size_t size);
/* Helper function for quick_sort */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size);
int get_max(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void bitonic_sort(int *array, size_t size);
size_t hoare_partition(int *array, size_t low, size_t high, size_t size);
void quick_sort_recursive_hoare(int *array, size_t low, size_t high, size_t size);
void quick_sort_hoare(int *array, size_t size);


#endif /* SORT_H */

