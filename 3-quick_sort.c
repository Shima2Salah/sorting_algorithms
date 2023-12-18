#include "sort.h"

/**
 * partitioning - func to partition quick sort
 * @array: input array
 * @low: min list index
 * @high: max list index
 * @size: Size of array
 * Return: integer
 */
int partitioning(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j, temp;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
if (i != j)
print_array(array, size);
}
}

temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
if (i + 1 != high)
print_array(array, size);

return (i + 1);
}

/**
 * recursive_sort - func to Quick Sort
 * @array: input array
 * @low: min list index
 * @high: max list index
 * @size: Size of array
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot = partitioning(array, low, high, size);

recursive_sort(array, low, pivot - 1, size);
recursive_sort(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - func for quick sort algorithm
 * @array: input array
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

recursive_sort(array, 0, size - 1, size);
}

