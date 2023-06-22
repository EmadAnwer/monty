#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{

	print_stack(my_data.stack);
}

void push(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	
	if (my_data.line_vactior[1])
		num = atoi(my_data.line_vactior[1]);
	
	
	add_dnodeint(stack, num);
}
