#include "monty.h"

/**
 * pall - prints all the values on the stack,
 *   starting from the top of the stack.
 * @stack: pointer to pointer to top of stack.
 * @line_number: the current line number in file we are reading from
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		fprintf(stdout, "%d\n", ptr->n);
		fflush(stdout);
		ptr = ptr->next;
	}
}
