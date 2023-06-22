#include "monty.h"
/**
 * main - monty code main func
 * @argc: number of arguments
 * @argv: monty file arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	ssize_t line = 1;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	opinput.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		content = NULL;
		line = getline(&content, &size, file);
		opinput.content = content;
		counter++;
		if (line > 0)
		{
			executeCmd(content, &stack, counter, file);
		}
		free(content);
	}
	freeStack(stack);
	fclose(file);
	return (0);
}
