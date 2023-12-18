#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - func for counting sort
 * @array: input array
 * @size: Array size
 */
void counting_sort(int *array, size_t size)
{
size_t i;
int max, m, *ptr, *count;
if (array == NULL || size < 2)
return;
max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
count = malloc((max + 1) * sizeof(int));
if (count == NULL)
return;
for (m = 0; m <= max; m++)
count[m] = 0;
for (i = 0; i < size; i++)
count[array[i]]++;
for (m = 1; m <= max; m++)
count[m] += count[m - 1];
for (m = 0; m < max; m++)
printf("%d, ", count[m]);
printf("%d\n", count[m]);
ptr = malloc(size * sizeof(int));
if (ptr == NULL)
{
free(count);
return;
}
for (m = size - 1; m >= 0; count[array[m]]--, m--)
ptr[count[array[m]] - 1] = array[m];
for (i = 0; i < size; i++)
{
array[i] = ptr[i];
}
free(count);
free(ptr);
}

