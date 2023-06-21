#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 2

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * TODO
 */
typedef struct my_data_s
{
	int line_number;
	char **opcode;
	char **line;
	stack_t **stack;
} my_data_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*error functions*/
void print_open_file_error(char *file_name);
void print_usage_error();
void print_invalid_instruction_error(int line_number, char *opcode_instruction);
void print_malloc_error();
void print_push_error(int line_number);
void print_empty_stack_error(int line_number);

/*execute functions*/
int execute_file(char *file_name);
void execute_line(char *line, int line_number);

/*instructions*/
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

/*linked list functions*/
size_t print_stack(const stack_t *h);
stack_t *add_stackint(stack_t **head, const int n);
stack_t *add_stackint_end(stack_t **head, const int n);
void free_stack(stack_t *head);
void delete_top_node(stack_t **stack);


/*helper*/
int is_number(const char *str);

extern my_data_t my_data;
#endif /*MONTY_H*/
