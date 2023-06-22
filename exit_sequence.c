#include "monty.h"

/**
 * exit_sequence - exits the program gracefully
 * @stack: pointer to pointer to top of stack
 * @exit_reason: success or failure
 * @file: pointer to the open file we are currently procesing
 * @lineptr: pointer to the buffer storing the contents of current line;
 *
*/
void exit_sequence(int exit_reason, stack_t **stack, FILE *file, char *lineptr)
{
	if (lineptr != NULL)
		free(lineptr);

	if (file)
		fclose(file);

	free_stack(stack);

	if (exit_reason == EXIT_SUCCESS)
	{
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
