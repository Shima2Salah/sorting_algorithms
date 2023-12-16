#include "sort.h"
/**
 * list_swap - func to swap list
 * @list: input list
 * @a: first node
 * @b: second node
 */
void list_swap(listint_t **list, listint_t *a, listint_t *b)
{
listint_t *temp;
listint_t *prev1 = a->prev;
listint_t *prev2 = b->prev;

if (prev1)
prev1->next = b;
else
*list = b;

if (prev2)
prev2->next = a;
else
*list = a;

a->prev = prev2;
b->prev = prev1;

temp = a->next;
a->next = b->next;
b->next = temp;

if (a->next)
a->next->prev = a;

if (b->next)
b->next->prev = b;

print_list(*list);
}
/**
 * insertion_sort_list - func for insertion sort
 * @list: input list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *prev;

if (!list || !*list || !(*list)->next)
return;

curr = (*list)->next;

while (curr)
{
prev = curr->prev;
while (prev && prev->n > curr->n)
{
list_swap(list, prev, curr);
prev = curr->prev;
}
curr = curr->next;
}
}
