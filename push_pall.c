#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

void push(stack_t **stack, unsigned int line_number)
{
	int num = 0;
	UNUSED(line_number);

		if (my_data.arg2)
			num = atoi(my_data.arg2);
		else
			print_push_error(line_number);

	add_dnodeint(stack, num);
}

void print_push_error(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

void free_everything()
{
	free_stack(my_data.stack);
	fclose(my_data.file);
	free(my_data.line);
}
