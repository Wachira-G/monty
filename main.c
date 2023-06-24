#include "monty.h"

int flagged = 0;

/**
 * main - entry point into our interpreter
 * @argc: number of arguments
 * @argv: array of arguments.
 *
 * Return: 0 always.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *lineptr = NULL, *opcode = NULL;
	int line_number = 1;
	size_t len;
	ssize_t nread;
	stack_t *stack = NULL;

	/* test for correct input file */
	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r"); /* open the file */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*read line by line  */
	while ((nread = getline(&lineptr, &len, file)) != -1)
	{
		opcode = strtok(lineptr, " \t\n\r"); /* (1st token) next is in push */

		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}

		else
		{/*find out the instruction and execute it*/
			execute(opcode, line_number, &stack, file, lineptr);
		}
		line_number++;
	} /* printf("read %d lines\n", line_number); */
	exit_sequence(EXIT_SUCCESS, &stack, file, lineptr);
	return (0);
}
