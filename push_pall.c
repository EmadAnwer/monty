#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

void push(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (my_data.arg2)
	{
		if(is_num(my_data.arg2))
		{
			num = atoi(my_data.arg2);
			add_dnodeint(stack, num);
		}
			
	}
	else
		print_push_error(line_number);

	
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

int is_num(char *num)
{
    int i = 0;

    if (num[i] == '-')
        i++;

    while (num[i])
    {
        if (!(num[i] >= '0' && num[i] <= '9'))
            return 0; /* Not a number */
        i++;
    }

    return 1; /* It's a number */
}
