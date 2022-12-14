#include "monty.h"

/**
 * pall - print
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	size_t size = 0;

	(void)(line_number);

	ptr = *stack;

	while (ptr != NULL)
	{
		size++;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	free(ptr);
}

/**
 * push - print
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */

void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	char *line = NULL;
	int number, isdigit;

	line = strtok(NULL, "\n");
	isdigit = is_digit(line);

	if (isdigit == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", arg.n_line);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	number = atoi(line);
	add_dnodeint(stack, number);
}

/**
 * void pint - function to print top
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */
/**
 * void pint(stack_t **stack, unsigned int line_number)
 * {
 *	(void)(line_number);
 * }
 */
/**
 * void pop - function to del element in a stack
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */

/**
 * void pop(stack_t **stack, unsigned int line_number)
 * {
 *	(void)(line_number);
 *	if (*stack != NULL)
 *		del_dnodeint_index(stack);
 *	else
 *	{
 *		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
 *		exit(EXIT_FAILURE);
 *	}
 * }
 */

