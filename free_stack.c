#include "monty.h"
/**
 * freeStack - frees a doubly linked list
 * @head: head of the stack
 */

void freeStack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
