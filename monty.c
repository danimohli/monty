#include "monty.h"

int DATA = 0;  /* Global variable definition */

/**
* main - Entry point for the Monty interpreter
* @argc: Argument count
* @argv: Argument vector
*
* Return: 0 on success, EXIT_FAILURE on error
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *buf = NULL, *opcode, *data;
	size_t num = 0;
	unsigned int line_number = 0;
	int x;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buf, &num, file) != -1)
	{
		line_number++;
		opcode = strtok(buf, " ");
		if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " ");
			if (data != NULL)
			{
				x = atoi(data);
				if (x != 0)
					DATA = x;
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
		}
		look_up(opcode, line_number, stack);
	}

	free(buf);
	fclose(file);
	return (EXIT_SUCCESS);
}
