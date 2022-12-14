#include "monty.h"

/**
 * swap - entry point
 * @stack:
 * @line_number:
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int value;

	if ((!stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = value;
}


/**
 * add - entry point
 * @stack:
 * @line_number:
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

void add(stack_t **stack, unsigned int line_number)
{
	int value1 = 0, sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	value1 = (*stack)->n;
	del_dnodeint_index(stack, 0);
	sum = value1 + (*stack)->n;
	(*stack)->n = sum;
}

/**
 * nop - entry point
 * @stack:
 * @line_number:
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */


void nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
