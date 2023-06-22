#include "monty.h"

void stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	my_data.mode = STACK;
}


void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	my_data.mode = QUEUE;
}
