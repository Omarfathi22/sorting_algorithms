#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
       return;

    current = (*list)->next;
    while (current != NULL)
    {
        next_node = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
            prev_node = current->prev;
            if (next_node != NULL)
                next_node->prev = prev_node;
            if (prev_node->prev != NULL)
                prev_node->prev->next = current;
            else
                *list = current;
            current->prev = prev_node->prev;
            prev_node->next = next_node;
            prev_node->prev = current;
            current->next = prev_node;
            print_list(*list);
        }
        current = next_node;
    }
}
