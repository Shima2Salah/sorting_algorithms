#include "sort.h"
/**
 * selection_sort - func for bubble sort
 * @array: input array
 * @size: Array size
 */
void selection_sort(int *array, size_t size)
{
int i, m, min, temp, index;
for (i = 0; i < size - 1; i++)
{
m = i;
min = array[m];
while (m < size)
{
if (array[m] < min)
{
min = array[m];
index = m;
}
m++;
}
if (array[i] > array[index])
{
temp = array[i];
array[i] = min;
array[index] = temp;
print_array(array, size);
}
}
}
