#include "monty.h"

int execute_file(char *file_name)
{
	FILE *file;
	char *line = NULL;
	size_t line_length = 0;
	ssize_t read;
	/*Open the file*/
	file = fopen(file_name, "r");
	if (file == NULL)
		print_open_file_error(file_name);
	my_data.file = file;
	/*Read and execute each line until the end of the file*/
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		my_data.line_number++;
		my_data.line = line;
		if (is_empty_line(my_data.line) == 1)
			execute_line(my_data.line, my_data.line_number);
	}
	free_stack(my_data.stack);
	fclose(file);
	free(line);
	return (0);
}
/*
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

*/
void execute_line(char *line, int line_number)
{
	int i;
	int is_instruction = -1;
	instruction_t instructions[] =
		{
			{"push", push},
			{"pop", pop},
			{"pall", pall},
			{"pint", pint},
			{"swap", swap},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{"add", add},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr},
			{"stack", stack},
			{"queue", queue},
		};
	/*strtok*/
	my_data.arg1 = strtok(line, " \n");
	my_data.arg2 = strtok(NULL, " \n");

	if (my_data.arg1[0] == '#')
	{
		nop(&my_data.stack, line_number);
		return;
	}
	for (i = 0; i < INSTRUCTIONS_COUNT; i++)
		if (strcmp(my_data.arg1, instructions[i].opcode) == 0)
		{

			is_instruction = i;
			break;
		}
	if (is_instruction != -1)
		instructions[i].f(&my_data.stack, line_number);
	else
		print_invalid_instruction_error(line_number, my_data.arg1);
}

int is_empty_line(char *line)
{
	int i;
	int length = strlen(line);

	if (length > 0)
	{
		/* Check if the line ends with '\n'*/
		if (line[length - 1] == '\n')
		{
			/*Check if the line contains any characters before '\n'*/
			for (i = 0; i < length - 1; i++)
			{
				if (line[i] != ' ')
					return 1;
			}
			return 0;
		}
	}

	return 0;
}
