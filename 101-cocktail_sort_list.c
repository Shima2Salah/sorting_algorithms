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
}
/**
 * cocktail_sort_list - func to coktail sort list
 * @list: input list
 */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current;


if (*list == NULL || (*list)->next == NULL)
return;
do {
swapped = 0;
current = *list;
while (current->next)
{
if (current->n > current->next->n)
{
list_swap(list, current, current->next);
swapped = 1;
print_list(*list);
current = current->prev;
}
current = current->next;
}
if (!swapped)
break;

while (current->prev != NULL)
{
if (current->n < current->prev->n)
{
list_swap(list, current->prev, current);
swapped = 1;
print_list(*list);
current = current->next;
}
current = current->prev;
}
} while (swapped);
}

