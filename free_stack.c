#include "monty.h"

/**
 * free_stack - frees the stack
 *
 * @stack: the pointer to the beginning of the stack
*/
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;
	stack_t *next_node;

	if (ptr != NULL)
	{
		while (ptr != NULL)
		{
			next_node = ptr->next;
			free(ptr);
			ptr = next_node;
		}

		*stack = NULL;
	}
}
