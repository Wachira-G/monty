#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * The integer stored at the top of the stack
 *  is treated as the ascii value of the character to be printed.
 * If the value is not in the ascii table (man ascii) print the error message
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
*/
void pchar(__attribute__((unused)) stack_t **stack, unsigned int line_number)
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
