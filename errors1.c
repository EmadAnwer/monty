#include "monty.h"

void print_usage_error()
{
	
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void print_open_file_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

void print_invalid_instruction_error(int line_number, char *opcode_instruction)
{
	free_everything();
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_instruction);
	exit(EXIT_FAILURE);
}

void print_malloc_error()
{
	free_everything();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
