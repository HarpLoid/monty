#include "monty.h"

/**
 * swap - swap the top two elements
 * of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	if (temp->next)
	{
		(*stack)->next = temp->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *stack;
	(*stack) = temp;
}
