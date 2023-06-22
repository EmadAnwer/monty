#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 14

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
	char *arg1;
	char *arg2;
	stack_t *stack;
	FILE *file;
	char *line;
} my_data_t;

extern my_data_t my_data;
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
void print_pint_error(int line_number);
void print_swap_error(int line_number);
void print_add_error(int line_number);
/*execute functions*/
int execute_file(char *file_name);
void execute_line(char *line, int line_number);

/*instructions*/
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);


/*linked list functions*/
size_t print_stack(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_stack(stack_t *head);
void delete_top_node(stack_t **stack);


/*helper*/

void free_everything();

int is_empty_line(char *line);
int is_num(char *num);
#endif /*MONTY_H*/
