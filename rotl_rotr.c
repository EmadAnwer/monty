#include "monty.h"

/*


   1 2 3 4 5 6 7 8 9
 0 1 2 3 4 5 6 7 8 9
rotl

*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int top;
	stack_t *c;
	UNUSED(line_number);
	if (stack != NULL || *stack != NULL || (*stack)->next != NULL)
	{
		top = (*stack)->n;
		c = *stack;
		while (c->next)
		{
			c->n = c->next->n;
			c = c->next;
		}
		c->n = top;
	}
}

void rotr(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);
}
