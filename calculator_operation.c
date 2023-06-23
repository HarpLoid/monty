#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer top of stack.
 * @line_number: file number.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _sub - subtracts the top element of the stack
 * from the second top element.
 * @stack: pointer top of stack.
 * @line_number: file number.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
