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

