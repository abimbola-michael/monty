#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct opinput_s - structs for arguments, line content, file,
 * @arg: argument passed
 * @file: pointer to the monty file
 * @content: line content
 * @stackorqueue: stack or queue value
 * Description: carries values through the program
 */
typedef struct opinput_s
{
	char *arg;
	FILE *file;
	char *content;
	int stackorqueue;
}  opinput_t;

extern opinput_t opinput;
int executeCmd(char *content, stack_t **head, unsigned int counter, FILE *file);
void freeStack(stack_t *head);
void push_func(stack_t **head, unsigned int number);
void pall_func(stack_t **head, unsigned int number);
void pint_func(stack_t **head, unsigned int number);
void pop_func(stack_t **head, unsigned int counter);
void swap_func(stack_t **head, unsigned int counter);
void add_func(stack_t **head, unsigned int counter);
void nop_func(stack_t **head, unsigned int counter);
void sub_func(stack_t **head, unsigned int counter);
void div_func(stack_t **head, unsigned int counter);
void mul_func(stack_t **head, unsigned int counter);
void mod_func(stack_t **head, unsigned int counter);
void pchar_func(stack_t **head, unsigned int counter);
void pstr_func(stack_t **head, unsigned int counter);
void rotl_func(stack_t **head, unsigned int counter);
void rotr_func(stack_t **head, __attribute__((unused)) unsigned int counter);
void queue_func(stack_t **head, unsigned int counter);
void stack_func(stack_t **head, unsigned int counter);
void addStack(stack_t **head, int n);
void addQueue(stack_t **head, int n);
#endif
