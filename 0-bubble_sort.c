#include "sort.h"
/**
 * bubble_sort - func for bubble sort
 * @array: input array
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
int temp;
unsigned long int i, j;
for (i = 0; i < size; i++)
{
for (j = 0; j < (size - i - 1); j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
print_array(array, size);
}
}
}
}
