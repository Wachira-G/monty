#include "monty.h"

/**
 * pop - removes the top element of the stack.
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		/*exit_sequence();*/
		flagged = 1;
		return;
	}
	*stack = (*stack)->next;
	free(ptr);
}
