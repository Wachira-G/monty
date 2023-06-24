#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * The top element of the stack becomes the last one,
 *  and the second top element of the stack becomes the first one.
 * rotl never fails.
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
 * If the stack contains less than two elements, print the error message
*/
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head, *rear, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	head = *stack;
	second = head->next;
	rear = second;
	while (rear->next != NULL)
		rear = rear->next;

	second->prev = NULL;
	head->prev = rear;
	head->next = NULL;
	rear->next = head;

	*stack = second;
}
