#include "monty.h"
/**
 * pint_func - prints the value at the top of the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void pint_func(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_func - removes the top element of the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void pop_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * stack_func - prints the top
 * @head: head of the stack
 * @counter: line number counter
 */
void stack_func(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	opinput.stackorqueue = 0;
}

/**
 * queue_func - prints the top
 * @head: head of the stack
 * @counter: line number counter
 */
void queue_func(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	opinput.stackorqueue = 1;
}
