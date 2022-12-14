#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

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

/**
 * struct arg_s- struct to manage access of arg to different function
 * @argv: array
 * @n_line: lines counter
 * @line: line of command
 * @stack_head: double linked list
 * @fp: file descriptor
 *
 * Description: all data used by various function
 */

typedef struct arg_t
{
	char **argv;
	ssize_t n_line;
	char *line;
	stack_t *stack_head;
	FILE *fp;
} arg_t;


/* ***** EXTERNE VARIABLE *************** */
extern arg_t arg;


/* function interpreter */
void intp_monty(void); /* open, read, close file and call cmp_op() */
void cmp_op(void);  /* search op function */

/* function associated : string, linked list */
int check_arg(char *s);
stack_t *add_dnodeint(stack_t **head, const int n);
int del_dnodeint_index(stack_t **head, unsigned int index);
void free_all(stack_t *head);

/* opcodes functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

int is_digit(char *string);

void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*associed function opcode*/
stack_t *add_dnodeint(stack_t **head, const int n);

int del_dnodeint_index(stack_t **head, unsigned int index);

void free_all(stack_t *head);
void free_dlist(stack_t *head);

#endif
