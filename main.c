#include "monty.h"

global_t dataStruct;

/**
 * change_last_character - change the last character('\n') in a line per ('\0')
 * @line: Line to modify
 * Return: returnless
 */
void change_last_character(char *line)
{
	int i = 0;

	while (line[i] != '\n')
	{
		i++;
	}
	line[i] = '\0';
}

/**
 * main - Entry point of project
 * @argc: acount of arguments
 * @argv: value of any argument
 * Return: 0 is sucessfull
 */
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *c = NULL;
	unsigned int line = 1;
	size_t sizeC = 0;
	stack_t *stackMonty = NULL;
	void (*cp_get_op_code)(stack_t **stack, unsigned int line);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
	while (getline(&c, &sizeC, fp) != -1)
	{
		change_last_character(c);
		dataStruct.lineTokenized = c;
		if (dataStruct.lineTokenized[0])
		{
			cp_get_op_code = (*get_op_code)();
			if (cp_get_op_code)
			{
				(*cp_get_op_code)(&stackMonty, line);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
				line, dataStruct.opCodeNoExist);
				exit(1);
			}
		}
		line++;
	}
	free(c), fclose(fp), free_dlistint(stackMonty);
	return (0);
}
