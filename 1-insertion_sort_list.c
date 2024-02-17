#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *current, *temp, *next_node;
        int value;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        current = (*list)->next;

        while (current != NULL)
        {
                value = current->n;
                temp = current->prev;
                next_node = current->next;

                while (temp != NULL && temp->n > value)
                {
                        temp->next = next_node;
                        if (next_node != NULL)
                                next_node->prev = temp;
                        
                        current->prev = temp->prev;
                        current->next = temp;

                        if (temp->prev != NULL)
                                temp->prev->next = current;

                        temp->prev = current;

                        if (current->prev == NULL)
                                *list = current;

                        print_list(*list);
                        temp = current->prev;
                }

                current = next_node;
        }
}
