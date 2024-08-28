#include "monty.h"
/**
 * push - stack function to push data to stack
 * @stack: pointer to stack to push to
 * @n: Data to push to stack
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->prev = NULL;

	if (*stack == NULL)
	{
		node->next = NULL;
		*stack = node;
		return;
	}

	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

/**
 * pall - to print out all data in stack
 * @stack: stack to out put
 */
void pall(stack_t **stack)
{
	stack_t *s = *stack;

	while (*s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
