#include "monty.h"

/**
 * nop - does absolutely nothing
 * @stack: pointer to the beginning of the stack
 * @line_number: the current line number in file we are reading from
*/
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	;
}
