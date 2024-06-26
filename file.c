#include "monty.h"
/**
 * is_numeric - Checks if a string is a valid integer.
 * @str: The string to check.
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing */
}
