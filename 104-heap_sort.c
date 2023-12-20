#include "sort.h"
#include <stdlib.h>
/**
 * swap_memb - func to swap members
 * @f: first input
 * @e: second input
 */
void swap_memb(int *f, int *e)
{
int temp = *f;
*f = *e;
*e = temp;
}
/**
 * sifts_Down - func to sifts down
 * @array: input array
 * @start: begining sift
 * @end: ending sift
 * @size: Array size
 */
void sifts_Down(int *array, size_t start, size_t end, size_t size)
{
size_t root = start;
while (root * 2 + 1 <= end)
{
size_t last_child = root * 2 + 1;
if (last_child + 1 <= end && array[last_child] < array[last_child + 1])
{
last_child += 1;
}
if (array[root] < array[last_child])
{
swap_memb(&array[root], &array[last_child]);
print_array(array, size);
root = last_child;
}
else
{
return;
}
}
}
/**
 * heapify_arr - func for heapifying
 * @array: input array
 * @size: Array size
 */
void heapify_arr(int *array, size_t size)
{
int start = (size - 2) / 2;
while (start >= 0)
{
sifts_Down(array, start, size - 1, size);
start--;
}
}
/**
 * heap_sort - func for heaping sort
 * @array: input array
 * @size: Array size
 */
void heap_sort(int *array, size_t size)
{
int end;
if (array == NULL || size < 2)
return;

heapify_arr(array, size);
for (end = size - 1; end > 0; end--)
{
swap_memb(&array[0], &array[end]);
print_array(array, size);
sifts_Down(array, 0, end - 1, size);
}
}

