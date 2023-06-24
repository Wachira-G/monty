#include "monty.h"

/**
 * execute - handles execution of the opcodes.
 * @opcode: instructions to execute
 * @line_number: current line number in file we are processing
 * @stack: containter that we store our data
 * @file: pointer to a file we are processing
 * @lineptr: buffer string the current line;
 * Return: success or fail of our functions.
 */
int execute(char *opcode, int line_number, stack_t **stack,
		FILE *file, char *lineptr)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		/*{"queue", queue}, {"stack", _stack},*/
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		flagged = 0;

		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			/* check flag and handle it */
			if (flagged)
			{
				exit_sequence(EXIT_FAILURE, stack, file, lineptr);
			}
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit_sequence(EXIT_FAILURE, stack, file, lineptr);
	return (1);
}
