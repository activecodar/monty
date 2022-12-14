#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	char *op_command;
	char *value;
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: failed to open file '%s'\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		op_command = strtok(line, " ");
		value = strtok(NULL, " ");
		if (strcmp(op_command, "push") == 0)
		{
			if (!isdigit(value))
			{
				fprintf(stderr, "L(%d): usage: push integer\n", __LINE__);
				return (EXIT_FAILURE);
			}
			push(&stack, atoi(value));
		}
		else
		{
			pall(&stack);
		}
	}
	return (0);

}
