#include "monty.h"

/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @value: The value to be added on the stack
 */

void push(stack_t **stack, int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = value;
	node->prev = NULL;
	node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = node;
	}

	*stack = node;
}

/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *node;

	if (!*stack)
	{
		return;
	}
	node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}

}
