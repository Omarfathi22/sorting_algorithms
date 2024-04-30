#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme
 * @array: The array to partition
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 * @size: Size of the array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);
    return (i + 1);
}

/**
 * _quick_sort - Recursively sorts an array of integers using the Quick sort algorithm
 *               (Lomuto partition scheme)
 * @array: The array to sort
 * @low: The index of the first element of the partition to be sorted
 * @high: The index of the last element of the partition to be sorted
 * @size: Size of the array
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = lomuto_partition(array, low, high, size);
        _quick_sort(array, low, pivot_idx - 1, size);
        _quick_sort(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _quick_sort(array, 0, size - 1, size);
}
