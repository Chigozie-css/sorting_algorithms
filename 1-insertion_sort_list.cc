#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	/* Declarations */
	listint_t *current, *temp, *next_node;
	int value;

	/* Check if list is NULL or has less than two elements */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	 while (current != NULL)
	 {
		 /* Store the value of the current node */
		 value = current->n;

		 /* Initialize temp to the previous node of current */
		 temp = current->prev;

		 /* Initialize next_node to the next node of current */
		 next_node = current->next;

		 /* Inner loop to find the correct position for the current node */
		 while (temp != NULL && temp->n > value)
		 {
			 temp->next = next_node;
			 /* Update links between nodes */
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
		 /* Move to the next node in the list */
		 current = next_node;
	 }
}
