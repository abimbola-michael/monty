#include "monty.h"
/**
 * div_func - divides the second top element of the stack by
 * the top element of the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void div_func(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (h->next->n) / (h->n);
	(h->next->n) = temp;
	*head = h->next;
	free(h);
}
