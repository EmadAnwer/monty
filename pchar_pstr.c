#include "monty.h"



void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if(stack == NULL || *stack == NULL)
		print_pchar_error(line_number);

	num = (*stack)->n ;
	if ((*stack)->n)
	{
		if (num >= 0 && num <= 127) 
		{
		printf("%c\n", num);
		}
		else
			print_pchar_error(line_number);
	}
}


void pstr(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}

void print_pchar_error(int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}