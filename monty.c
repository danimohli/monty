#include "monty.h"
/**
 * main - the starting point of excution
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on Successful
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *buf = NULL, *opcode, *data;
	int DATA = 0, x;
	unsigned int line_number = 0;
	size_t num = 0;
	FILE *file;

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
			x = atoi(data);
			if (data == NULL || (x == 0 && strcmp(data, "0") != 0))
			{
				fprintf(stderr, "L%u: usage: push integer", line_number);
				exit(EXIT_FAILURE);
			}
			DATA = x;
		}
		look_up(opcode, line_number, stack);
	}
	free(buf);
	fclose(file);
	return (EXIT_SUCCESS);
}
