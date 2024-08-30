#include "monty.h"
/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack: The stack location
 * @line_number: the current line number in the bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	next = (*stack)->next;
	result = curr->n + next->n;

	next->n = result;
	*stack = next;

	free(curr);
}

/**
 * nop - the opcode nop doesn't do anything
 * @stack: stack
 * @line_number: the current line number in the bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - The opcode sub, sub the top two elements of the stack.
 * @stack: The stack location
 * @line_number: the current line number in the bytecode file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	next = (*stack)->next;
	result = next->n - curr->n;

	next->n = result;
	*stack = next;

	free(curr);
}
