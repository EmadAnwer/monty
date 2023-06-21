#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{

	print_stack(*stack);
}

void push(stack_t **stack, unsigned int line_number)
{
	char *str_num;
	int num = 0;

	str_num = strtok(*my_data.opcode, " ");
	printf("num =  %s", str_num);
	
	num = atoi(str_num);
	add_stackint(stack, num);
}
