#include "sort.h"

/**
 * swap - Swaps two integers in an array and prints the array
 * @array: The array to be modified
 * @size: The size of the array
 * @a: Index of the first integer
 * @b: Index of the second integer
 */
void swap(int *array, size_t size, int a, int b)
{
    int temp;

    if (array[a] != array[b])
    {
        temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        print_array(array, size);
    }
}

/**
 * sift_down - Sifts down the element at 'root' to its proper position
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The root index of the current subtree
 * @max: The maximum index in the heap
 */
void sift_down(int *array, size_t size, int root, int max)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < max && array[left] > array[largest])
        largest = left;

    if (right < max && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(array, size, root, largest);
        sift_down(array, size, largest, max);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(array, size, 0, i);
    }
}
