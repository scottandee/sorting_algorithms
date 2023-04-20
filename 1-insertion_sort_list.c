#include "sort.h"

/**
  * insertion_sort_list - sorts a doubly linked list of
  * integers in ascending order using the Insertion sort algorithm
  * @list: this contains the integers to be sorted
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp1;/*This stores the pointer for the outer loop*/
	listint_t *temp2;/*This stores the pointer for insertion*/

	temp1 = *list;

	while (temp1 != NULL)
	{
		temp2 = temp1;

		while (temp2->prev != NULL)
		{
			if (temp2->n < temp2->prev->n)
			{
				swap(temp2, list);

				print_list(*list);
			}
			else
			{
				break;
			}
		}
		temp1 = temp1->next;
	}
}

/**
  * swap - this function swaps two nodes
  * @cur: this is the current node that will
  * be swapped with the previous node
  * @head: this is the head of the singly linked list
  */

void swap(listint_t *cur, listint_t **head)
{
	listint_t *buffer1, *buffer2;

	if (cur->prev->prev == NULL)
	{
		cur->next->prev = cur->prev;
		cur->prev->prev = cur;
		cur->prev->next = cur->next;
		cur->next = cur->prev;
		cur->prev = NULL;
		*head = cur;
	}
	else if (cur->next == NULL)
	{
		cur->prev->prev->next = cur;
		buffer1 = cur->prev->prev;
		cur->prev->prev = cur;
		cur->prev->next = NULL;
		cur = cur->prev;
		cur->prev->next = cur;
		cur->prev->prev = buffer1;
	}
	else
	{
		buffer1 = cur->next;
		cur->next->prev = cur->prev;
		cur->next = cur->prev;
		cur->prev->prev->next = cur;
		buffer2 = cur->prev->prev;
		cur->prev->prev = cur;
		cur->prev = buffer2;
		cur = cur->next;
		cur->next = buffer1;
	}
}
