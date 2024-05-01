#include <stdlib.h>
#include "sort.h"

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list = NULL;
    listint_t *node = NULL;
    size_t i;

    for (i = 0; i < size; i++)
    {
        node = malloc(sizeof(listint_t));
        if (!node)
        {
            free_listint(list);
            return NULL;
        }
        node->n = array[i];
        node->prev = NULL;
        node->next = list;
        if (list)
            list->prev = node;
        list = node;
    }

    return list;
}
