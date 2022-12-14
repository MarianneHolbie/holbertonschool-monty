#include "monty.h"

/**
 * void pall - print
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * void push - print
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *line = NULL;
	int number, isdigit;

	line = strtok(NULL, "\n");
	isdigit = is_digit(line);

	if (isdigit == -1)
	{
		fprintf(stderr, "L%u: usage push integer\n", line_number);
		free_all(*stack);
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
 *void pint(stack_t **stack, unsigned int line_number)
 *{
 *	(void)(line_number);


 * }
 */

/**
 * void pop - function to del element in a stack
 * @stack: double pointer
 * @line_number: unsigned int
 * Description: function that print with opcodes pall
 * retur: 0


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
