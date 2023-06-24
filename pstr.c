#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 *  followed by a new line.
 * The integer stored in each element of the stack
 *  is treated as the ascii value of the character to be printed
 * The string stops when either:
 *  the stack is over
 *  the value of the element is 0
 *  the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
*/
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!*stack)
	{
		fprintf(stdout, "\n");
		fflush(stdout);
		return;
	}

	else
	{
		while (ptr != NULL)
		{
			if (ptr->n > 127 || ptr->n <= 0)
			{
				fprintf(stdout, "\n");
				fflush(stdout);
				return;
			}
			fprintf(stdout, "%c", ptr->n);
			fflush(stdout);
			ptr = ptr->next;
		}
	}
	fprintf(stdout, "\n");
	fflush(stdout);
}
