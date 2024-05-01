#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list = NULL;
    listint_t *node = NULL;
    int i;

    for (i = size - 1; i >= 0; i--)
    {
        node = malloc(sizeof(listint_t));
        if (!node)
        {
            /* Free already allocated memory */
            while (list)
            {
                listint_t *temp = list->next;
                free(list);
                list = temp;
            }
            return (NULL);
        }
        node->n = array[i];
        node->prev = NULL;
        node->next = list;
        if (list)
            list->prev = node;
        list = node;
    }
    return (list);
}

/**
 * print_listint - Prints a doubly linked list of integers
 *
 * @list: Pointer to the first element of the list
 */
void print_listint(const listint_t *list)
{
    const listint_t *current = list;

    while (current)
    {
        printf("%d", current->n);
        if (current->next)
            printf(" <-> ");
        current = current->next;
    }
    printf("\n");
}

/**
 * free_listint - Frees a doubly linked list
 *
 * @list: Pointer to the first element of the list
 */
void free_listint(listint_t *list)
{
    listint_t *temp;

    while (list)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t size = sizeof(array) / sizeof(array[0]);
    listint_t *list = create_listint(array, size);

    if (!list)
    {
        fprintf(stderr, "Failed to create list\n");
        return (1);
    }

    printf("Original list: ");
    print_listint(list);
    printf("\n");

    cocktail_sort_list(&list);

    printf("Sorted list: ");
    print_listint(list);

    free_listint(list);

    return (0);
}
