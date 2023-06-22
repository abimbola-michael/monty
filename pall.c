#include "monty.h"
/**
 * pall_func - prints all element of the stack
 * @head: head of the stack
 * @counter: no used
 */
void pall_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
