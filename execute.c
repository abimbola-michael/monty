#include "monty.h"
/**
* executeCmd - executes opcode
* @stack: head of linked list
* @counter: counter for line
* @file: pointer to the monty file
* @content: content of the line
* Return: 1 if successfully 0
*/
int executeCmd(char *content, stack_t **stack, unsigned int counter,
		FILE *file)
{
	instruction_t op_structs[] = {
				{"push", push_func}, {"pall", pall_func},
				{"pint", pint_func}, {"pop", pop_func},
				{"swap", swap_func}, {"add", add_func},
				{"nop", nop_func}, {"sub", sub_func},
				{"div", div_func}, {"mul", mul_func},
				{"mod", mod_func}, {"pchar", pchar_func},
				{"pstr", pstr_func}, {"rotl", rotl_func},
				{"rotr", rotr_func}, {"queue", queue_func},
				{"stack", stack_func}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *opChar;

	opChar = strtok(content, " \n\t");
	if (opChar && opChar[0] == '#')
		return (0);
	opinput.arg = strtok(NULL, " \n\t");
	while (op_structs[i].opcode && opChar)
	{
		if (strcmp(opChar, op_structs[i].opcode) == 0)
		{	op_structs[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opChar && op_structs[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opChar);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
