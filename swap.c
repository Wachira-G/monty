#include "monty.h"

/**
 * swap -  swaps the top two elements of the stack.
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
 * If the stack contains less than two elements, print the error message
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *ptr2;
	int top_value, next_value;

	if (stack == NULL || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		/*and exit with the status EXIT_FAILURE")*/
		flagged = 1;
		return;
	}
	ptr = *stack;
	ptr2 = ptr->next;
	top_value = ptr->n;
	next_value = ptr2->n;

	ptr->n = next_value;
	ptr2->n = top_value;
}
