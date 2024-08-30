#include "monty.h"

/**
 * look_up - call-up function
 * @opcode: opcode to lookup
 * @line_number: argument to pass to function
 * @stack: the stack
 */
void look_up(char *opcode, unsigned int line_number, stack_t *stack)
{
	int x;

	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"NULL", NULL}
	};

	for (x = 0; array[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, array[x].opcode) == 0)
		{
			array[x].f(&stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
