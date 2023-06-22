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
		execute_line(line, my_data.line_number);
		
	}
	free_stack(my_data.stack);
	fclose(file);
	free(line);
}

void execute_line(char *line, int line_number)
{
	int i;
	char *tok;
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	/*strtok*/
	my_data.line_vactior = malloc(sizeof(char *) * 2);
	if (my_data.line_vactior == NULL)
		print_malloc_error();

	tok = strtok(line, " \n");
	my_data.line_vactior[0] = malloc(strlen(tok) + 1);
	if (my_data.line_vactior[0] == NULL)
		print_malloc_error();
	strcpy(my_data.line_vactior[0], tok);

	tok = strtok(NULL, " \n");
	if (tok)
	{
		my_data.line_vactior[1] = malloc(strlen(tok) + 1);
		if (my_data.line_vactior[1] == NULL)
			print_malloc_error();
		strcpy(my_data.line_vactior[1], tok);
	}

	for (i = 0; i < INSTRUCTIONS_COUNT; i++)
		if (strcmp(my_data.line_vactior[0], instructions[i].opcode) == 0)
			instructions[i].f(&my_data.stack, my_data.line_number);
	
	freeCharVector(my_data.line_vactior, 2);
}

void freeCharVector(char **vector, int size)
{
	int i;
	/*Free the memory for each string in the vector*/
	for (i = 0; i < size; i++)
	{
		free(vector[i]);
	}

	/*Free the memory for the vector itself*/
	free(vector);

	
}
