#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_sub_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_sub_error(line_number);
}

void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_add_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_add_error(line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_mod_error(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			print_div_by_zero_error(line_number);
		(*stack)->next->n %= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_mod_error(line_number);
}

void print_mod_error(int line_number)
{

	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

void print_add_error(int line_number)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

void print_sub_error(int line_number)
{

	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
