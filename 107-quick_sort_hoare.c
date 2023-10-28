#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array to be modified
 * @a: Index of the first integer
 * @b: Index of the second integer
 */
void swap(int *array, int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The low index of the partition
 * @high: The high index of the partition
 * Return: The pivot index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

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

        swap(array, i, j);
    }
}

/**
 * quick_sort_recursive - Recursively sorts a partition of the array
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The low index of the partition
 * @high: The high index of the partition
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, size, low, high);
        quick_sort_recursive(array, size, low, pivot);
        quick_sort_recursive(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, size, 0, size - 1);
}
