#include "monty.h"

/**
 * add - adds top two elements of the stack
 *  and the top element is removed
 *  so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
 * If the stack contains less than two elements, print the error message
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *ptr2;
	int top_value, next_value, result;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		/*and exit with the status EXIT_FAILURE")*/
		flagged = 1;
		return;
	}
	ptr = *stack;
	ptr2 = ptr->next;
	top_value = ptr->n;
	next_value = ptr2->n;

	result = top_value + next_value;
	ptr2->n = result;
	pop(stack, line_number);
}
