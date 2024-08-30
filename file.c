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
/**
 * pchar - The opcode pchar prints the char at the top of the stack.
 * @stack: The stack
 * @line_number: the line number of read file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii = (*stack)->n;

	if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
	{
		printf("%c\n", ascii);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pstr - The opcode pstr prints the string starting at the top of the stack
 * @stack: The stack
 *  @line_number: the line number of read file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void)line_number;

	while (h != NULL)
	{
		if ((h->n >= 65 && h->n <= 90) || (h->n >= 97 && h->n <= 122))
			printf("%c", h->n);
		else
			break;
		h = h->next;
	}
	printf("\n");
}
