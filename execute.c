#include "monty.h"

int execute_file(char *file_name)
{
	FILE *file;
	char *line = NULL;
	size_t line_length = 0;
	ssize_t read;
	int line_number = 0;
	/*Open the file*/
	file = fopen(file_name, "r");
	if (file == NULL)
		print_open_file_error(file_name);

	/*Read and execute each line until the end of the file*/
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		line_number++;
		printf("%s", line);
		/*execute_line(line, );*/
	}

	fclose(file);
	/*
	TODO: free memory
	*/
}

void execute_line(char *line, int line_number)
{
	char *opcode_instruction;
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	/*strtok*/
	
	
}

int get_opcode_function_number(char *opcode_instruction)
{
	int i;

	for (i = 0; opcode_instructions[i]; i++)
		if (strcmp(opcode_instruction, opcode_instructions) == 0)
			return (i);
	return (-1);
}
