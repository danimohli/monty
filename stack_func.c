#include "monty.h"
/**
 * push - stack function to push data to stack
 * @stack: pointer to stack to push to
 * @line_number: the current line number in the bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = DATA;
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
	(void) line_number;
}

/**
 * pall - to print out all data in stack
 * @stack: stack to out put
 * @line_number: the current line number in the bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	while (s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
	(void) line_number;
}
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: the current line number in the bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - stack function to remove top element of the stack
 * @stack: stack to operate on or to remove from
 * @line_number: the current line number in the bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	next = (*stack)->next;
	*stack = next;

	free(curr);

	if (next != NULL)
		next->prev = NULL;
}
/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: stack where the changes should take place
 * @line_number: the current line number in the bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int x;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}
