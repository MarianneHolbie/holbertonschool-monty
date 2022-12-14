#include "monty.h"

/**
 * nop- function that do anything !
 * @stack: s tack
 * @line_number: number of line of the cmd
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add- add the two top element on stack, suppress one and give result
 * @stack: stack
 * @line_number: number of line of the cmd
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	int value1 = 0, sum = 0;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	/* stock value of first node in the stack */
	value1 = (*stack)->n;

	/* delete the first node of stack */
	del_dnodeint_index(stack, 0);

	/* update value of first node by add value of node delete */
	sum = value1 + (*stack)->n;
	(*stack)->n = sum;

}
