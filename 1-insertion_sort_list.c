#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @n1: First node
 * @n2: Second node
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (*list == NULL || n1 == NULL || n2 == NULL)
		return;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;

	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;

	if (n1->next != NULL)
		n1->next->prev =n1;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: Pointer to the head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp, temp->prev);
			print_list(*list);
			temp = temp->prev;
		}
	}
}
