#include "sort.h"
/**
 * shell_sort - func to sort array
 * @array: input array
 * @size: input size
 */
void shell_sort(int *array, size_t size)
{
int temp;
size_t f, e, g = 1;
while (g <= size / 3)
{
g = g * 3 + 1;
}
while (g > 0)
{
for (f = g; f < size; f++)
{
temp = array[f];
e = f;
while (e >= g && array[e - g] > temp)
{
array[e] = array[e - g];
e -= g;
}
array[e] = temp;
}
g = (g - 1) / 3;
print_array(array, size);
}
}
