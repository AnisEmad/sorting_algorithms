#include "sort.h"

/**
 * insertion_sort_list - sort a double linked list by insertion sort
 *
 * Return: void
 *
 * @list: the list to sort
*/


void insertion_sort_list(listint_t **list)
{
	listint_t *slow, *itr, *fast;

	if (list == NULL || *list == NULL)
		return;

	itr = *list;
	while (itr != NULL)
	{
		slow = itr->prev;
		fast = itr;
		while (slow != NULL)
		{
			if (fast->n >= slow->n)
				break;
			slow->next = fast->next;
			fast->prev = slow->prev;
			slow->prev = fast;
			fast->next = slow;
			if (fast->prev != NULL)
				fast->prev->next = fast;
			if (slow->next != NULL)
				slow->next->prev = slow;
			slow = fast->prev;
			if (slow == NULL)
				*list = fast;
			print_list(*list);
		}
		itr = itr->next;
	}
}
