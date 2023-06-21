#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_empty_stack_error(line_number);
	
	delete_top_node(stack);
}

void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

void print_empty_stack_error(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack", line_number);
	exit(EXIT_FAILURE);
}
