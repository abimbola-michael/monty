#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @head: head of the stack
 * @counter: line number counter
 */
void push_func(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (opinput.arg)
	{
		if (opinput.arg[0] == '-')
			j++;
		for (; opinput.arg[j] != '\0'; j++)
		{
			if (opinput.arg[j] > 57 || opinput.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(opinput.file);
			free(opinput.content);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(opinput.file);
		free(opinput.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(opinput.arg);
	if (opinput.stackorqueue == 0)
		addStack(head, n);
	else
		addQueue(head, n);
}

/**
 * addStack - adds a new node to the stack
 * @head: head of the stack
 * @n: new_value
 */
void addStack(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addQueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 */
void addQueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
