#include "monty.h"



void sub(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}


void add(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}


void mod(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}
