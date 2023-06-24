#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * The last element of the stack becomes the top one,
 * rotl never fails.
 *
 * @stack: pointer to the beginnig of the stack
 * @line_number: the current line number in file we are reading from
 * If the stack contains less than two elements, print the error message
*/
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head, *rear, *second_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	head = *stack;
	rear = head;
	while (rear->next != NULL)
		rear = rear->next;

	second_last = rear->prev;
	rear->next = head;
	head->prev = rear;
	second_last->next = NULL;
	rear->prev = NULL;

	*stack = rear;
}
