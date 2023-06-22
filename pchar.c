#include "monty.h"

/**
 * pint - prints the value at the top of the stackfollowed by a new line.
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
*/
void pint(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		/*exit sequence*/
		flagged = 1;
		return;
	}

	if ((*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		/*exit sequence*/
		flagged = 1;
		return;
	}
	fprintf(stdout, "%c\n", (*stack)->n);
	fflush(stdout);
}
