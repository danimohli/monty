#include "monty.h"
/**
 * mod - The opcode mod div the top two elements of the stack.
 * @stack: The stack location
 * @line_number: the current line number in the bytecode file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	next = (*stack)->next;
	result = next->n % curr->n;

	next->n = result;
	*stack = next;

	free(curr);
}
