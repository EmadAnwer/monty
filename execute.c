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
		execute_line(line, my_data.line_number);
		
	}
	free_stack(my_data.stack);
	fclose(file);
	free(line);
	return (0);
}

void execute_line(char *line, int line_number)
{
	int i;
	char *tok;
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	/*strtok*/
	my_data.line_vactior = malloc(sizeof(char *) * 3);
	if (my_data.line_vactior == NULL)
		print_malloc_error();
	
	my_data.line_vactior[0] = NULL;
    my_data.line_vactior[1] = NULL;
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
			instructions[i].f(&my_data.stack, line_number);
	
	free_vector(my_data.line_vactior);
}

void free_vector(char **argv)
{
	int i = 0;
	if (argv == NULL)
		return;

	for (i = 0; i < 2; i++)
	{
		if (argv[i] != NULL)
			free(argv[i]);
	}

	free(argv);
}
