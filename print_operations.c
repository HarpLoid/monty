#include "monty.h"

/**
 * pall - print all nodes in stack
 * @stack: pointer to top of the stack
 * @line_number: bytecode line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void) line_number;
	
	if (!stack || !*stack)
		return;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print top node in stack
 * @stack: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if(!stack || !*stack)
	{
		printf("L%u: cant pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - doesn't do nothing.
 * @stack: head of stack.
 * @line_number: bytecode file line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
