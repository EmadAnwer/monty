#include "monty.h"


/*

	prints the value at the top of the stack, followed by a new line.
	If the stack is empty,
		print the error message "L<line_number>: can't pint, stack empty"
		, followed by a new line, and exit

*/
void pint(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}


void print_pint_error(int line_number)
{
	
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
