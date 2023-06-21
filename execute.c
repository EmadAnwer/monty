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

	/*Read and execute each line until the end of the file*/
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		my_data.line_number++;
		my_data.line = &line;
		execute_line(*my_data.line, my_data.line_number);
	}

	fclose(file);
}

void execute_line(char *line, int line_number)
{
	int i;
	char *opcode_instruction;
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	/*strtok*/
	opcode_instruction = strtok(line, " ");
	my_data.line = &line;
	my_data.opcode = &opcode_instruction;
	for (i = 0; i < INSTRUCTIONS_COUNT; i++)
		if (strcmp(opcode_instruction, instructions[i].opcode) == 0)
			instructions[i].f(my_data.stack, my_data.line_number);
}
