#include "monty.h"


/*


 1 2 3 4 5 6 7 8 9 0
 0 1 2 3 4 5 6 7 8 9
rotl

*/
void rotl(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	if(stack != NULL || *stack != NULL)
	{
		add_stackint_end(stack , (*stack)->n);
		delete_top_node(stack);
	}

}


void rotr(stack_t **stack, unsigned int line_number)
{
	if(stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);

}
