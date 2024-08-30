#include "monty.h"
/**
 * _getline - Personal implementation of getline
 * @lineptr: Buffer to save read str
 * @n: nth byte to read
 * @stream: file stream
 * Return: Nth byte read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer;
	int c;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	buffer = *lineptr;

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			buffer = realloc(buffer, *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
		}
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	buffer[i] = '\0';
	return ((c == EOF && i == 0) ? -1 : (ssize_t)i);
}
