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

	stack_t *head;
	int len = 0, tmp;

	head = *stack;

	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	tmp = head->n;
	head->n = head->next->n;
	head->next->n = tmp;
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
	stack_t *head = NULL;
	int h;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	h = head->n;
	head->next->n = h;
	del_dnodeint_index(stack, 0);
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
