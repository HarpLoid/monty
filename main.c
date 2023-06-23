#include "monty.h"

/**
 * main - interpreter
 * @argc: argument count
 * @argv: arguments list
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd, pushflag = 0;
	unsigned int line = 1;
	ssize_t bytes_read;
	char *buffer, *token, *delim = "\n\t\a\r ;:";
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, 10000);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		if (pushflag == 1)
		{
			push(&stack, line, token);
			pushflag = 0;
			token = strtok(NULL, delim);
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			pushflag = 1;
			token = strtok(NULL, delim);
			continue;
		}
		else
		{
			if (get_func(token) != 0)
			{
				get_func(token)(&stack, line);
			}
			else
			{
				free_list(&stack);
				printf("L%u: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, delim);
	}
	free_list(&stack);
	free(buffer);
	close(fd);
	return(0);
}
