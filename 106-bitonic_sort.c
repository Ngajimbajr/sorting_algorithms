#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array to be modified
 * @i: Index of the first integer
 * @j: Index of the second integer
 */
void swap(int *array, size_t i, size_t j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    printf("Swap: ");
    print_array(array, j + 1);
}

/**
 * bitonic_merge - Merges two halves of the array in increasing order
 * @array: The array to be sorted
 * @size: The size of the array
 * @up: 1 if merging in increasing order, 0 if merging in decreasing order
 */
void bitonic_merge(int *array, size_t size, int up)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t i;

        for (i = 0; i < mid; i++)
        {
            if ((array[i] > array[i + mid]) == up)
                swap(array, i, i + mid);
        }

        bitonic_merge(array, mid, up);
        bitonic_merge(array + mid, mid, up);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to be sorted
 * @size: The size of the array
 * @up: 1 if sorting in increasing order, 0 if sorting in decreasing order
 */
void bitonic_sort_recursive(int *array, size_t size, int up)
{
    if (size > 1)
    {
        size_t mid = size / 2;

        bitonic_sort_recursive(array, mid, 1);
        bitonic_sort_recursive(array + mid, mid, 0);

        bitonic_merge(array, size, up);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, size, 1);
}
