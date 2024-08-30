#include "monty.h"

int DATA = 0;

/**
 * open_file - Opens the file and returns the file pointer.
 * @filename: The name of the file to open.
 *
 * Return: File pointer on success, NULL on failure.
 */
FILE *open_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * parse_push_argument - Parses the argument for the push opcode.
 * @data: The argument for push.
 * @line_number: The current line number.
 *
 * Return: The integer value of the argument.
 */
int parse_push_argument(char *data, unsigned int line_number)
{
	int value = atoi(data);

	if (value == 0 && strcmp(data, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (value);
}

/**
 * process_line - Processes each line of the bytecode file.
 * @buf: The buffer containing the line.
 * @stack: Pointer to the stack.
 * @line_number: The current line number.
 */
void process_line(char *buf, stack_t **stack, unsigned int line_number)
{
	char *opcode, *data;
	int value;

	opcode = strtok(buf, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		data = strtok(NULL, " \t\n");
		if (data == NULL || (!isdigit(data[0]) && !(data[0] == '-'
						&& isdigit(data[1]))))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(data);
		DATA = value;
	}
	look_up(opcode, line_number, stack);
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *buf = NULL;
	size_t num = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", "monty");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (_getline(&buf, &num, file) != -1)
	{
		line_number++;
		process_line(buf, &stack, line_number);
	}
	free(buf);
	fclose(file);
	pop(&stack, line_number);

	return (EXIT_SUCCESS);
}
