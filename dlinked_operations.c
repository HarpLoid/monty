#include "monty.h"

/**
 * add_dnode_end - adds a new node
 * at the end of a dlistint_t list.
 * @head: head of doubly linked list.
 * @n: element of the node.
 *
 * Return: 0 on success
 * or -1 if it failed
 */
int add_end_node(stack_t **head, int n)
{
	stack_t *node;

	if (!head)
		return (-1);

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		printf("Error: malloc failed");
		return (-1);
	}

	node->n = n;

	if (!(*head))
	{
		*head = node;
	}
	else
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
	return (0);
}

/**
 * delete_end_node - deletes node at end of list
 * @head: pointer to head of list
 */
void delete_end_node(stack_t **head)
{
	stack_t *delete;

	delete = *head;

	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(delete);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(delete);
	}
}

/**
 * free_list - frees a list
 * @head: pointer to head of list
 */
void free_list(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
