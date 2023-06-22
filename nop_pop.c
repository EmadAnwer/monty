#include "monty.h"
/**
 * pop - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_empty_stack_error(line_number);

	delete_top_node(stack);
}
/**
 * nop - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * print_empty_stack_error - .
 * @line_number: Line number of the current operation
 */
void print_empty_stack_error(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
