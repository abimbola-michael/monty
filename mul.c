#include "monty.h"
/**
 * mul_func - multiplies the second top element of the stack
 * with the top element of the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void mul_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
