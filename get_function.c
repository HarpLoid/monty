#include "monty.h"

/**
 * get_func - function to select correct operation function
 * @token: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_func(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] ={
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		/*{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},*/
		{NULL, NULL},
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
