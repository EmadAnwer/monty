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


/*

	The opcode swap swaps the top two elements of the stack.

	If the stack contains less than two elements
		print the error message L<line_number>: can't swap, stack too short,


*/
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if((*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
		print_swap_error(line_number);
}


void print_swap_error(int line_number)
{
	
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
