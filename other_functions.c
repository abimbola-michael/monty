#include "monty.h"
/**
  * rotl_func- rotates the stack to the top
  * @head: head of the stack
  * @counter: line number counter
  * Return: no return
  */
void rotl_func(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}

/**
  * rotr_func- rotates the stack to the bottom
  * @head: head of the stack
  * @counter: line number counter
  * Return: no return
  */
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

/**
 * pstr_func - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: head of the stack
 * @counter: line number counter
 */
void pstr_func(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * swap_func - swaps the top 2 elements of the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void swap_func(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

/**
  * sub_func- subtracts the top element from the second top element
  * of the stack
  * @head: head of the stack
  * @counter: line number counter
  * Return: no return
  */
void sub_func(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sub, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
