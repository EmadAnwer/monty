#include "monty.h"

/*


	2 3 4 5 6 7 8 9 0

rotl

*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int top = 0;
	stack_t *c = NULL;
	UNUSED(line_number);
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
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
	int last = 0;
	stack_t *c = NULL;
	UNUSED(line_number);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		c = *stack;

		while (c->next != NULL)
		{
			last = c->n;
			c = c->next;
		}

		last = c->n;

		while (c->prev != NULL)
		{
			c->n = c->prev->n;
			c = c->prev;
		}

		(*stack)->n = last;
	}
}
