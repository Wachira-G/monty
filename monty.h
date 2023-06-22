#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

extern int data;
extern int flagged;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue.)
 * @n: integer
 * @prev: points to the previous element of the stack(or queue).
 * @next: points to the next element of the stack(or queue).
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function.
 * @opcode: the opcode.
 * @f: function to hand the opcode.
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *opcode, int line_number, stack_t **stack,
		FILE *file, char *lineptr);

void free_stack(stack_t **stack);
void exit_sequence(int exit_reason, stack_t **stack,
		FILE *file, char *lineptr);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);

int isvalidint(char *data_str);

#endif /* MONTY_h */
