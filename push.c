#include "monty.h"

/**
 * push - pushes an element onto the stack
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
 *
*/
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	char *data_str = NULL,  *endptr = NULL;
	int data = 0, base = 10;
	long long_data;

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/* exit sequence */
		flagged = 1;
		return;
	}

	data_str = strtok(NULL, " \t\n\r");
	/* process data here*/
	if (isvalidint(data_str) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		/* exit sequence */
		flagged = 1;
		free(new_node); /* was not inserted onto stack so free*/
		return;
	}

	long_data = strtol(data_str, &endptr, base);
	data = (int) long_data;
	/*printf("data_str is %s data is %d\n", data_str, data);*/

	new_node->n = data;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL) /* non-empty*/
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
 * isvalidint - checks if a string can be converted into an int successfully
 * @data_str: the string we are checking
 * Return: success(1) of failure (-1);
*/
int isvalidint(char *data_str)
{
	long data;
	char *endptr = NULL;
	int base = 10;

	if (data_str == NULL)
		return (-1);
	data = strtol(data_str, &endptr, base);
	if ((errno == ERANGE && (data == LONG_MAX || data == LONG_MIN))
			|| errno == EINVAL)
		return (-1);
	/* Check for trailing characters after valid integer-*/
	/*ensures that we reject strings like "123a" or "123 456 - */
	while (*endptr != '\0')
	{
		if (!isspace(*endptr))
			return (-1);
		endptr++;
	}
	return (1);
}
