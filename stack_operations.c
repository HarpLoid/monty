#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: pointer to top element of stack.
 * @line_number: line number in file.
 * @n: element to push into stack.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, const char *n)
{
	int num;
	(void) line_number;

	if (!stack)
		return;

	num = is_number(n);
	if (num == -1)
	{
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(stack, atoi(n)) == -1)
		{
			free_list(stack);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to top od the stack
 * @line_number: line number of command
 * 
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(stack);
}

/**
 * is_number - checks if a string
 * is only digits.
 * @n: string to check if is number.
 *
 * Return: 0 if is number and -1 on failure.
 */
int is_number(const char *n)
{
	int i = 0;
	
	if (*n == '-')
		i = 1;

	while (*(n + i))
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
		i++;
	}
	return (0);
}
