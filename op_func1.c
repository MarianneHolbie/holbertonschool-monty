#include "monty.h"

/**
 * push- function that pushes an element to the stack
 * @stack: point to dubble linked list
 * @line_number: line number in the file
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int number, is_digit;
	char *line = NULL;

	line = strtok(NULL, "\n");

	/* check if it is digit or not */
	is_digit = check_arg(line);

	/* if is not digit */
	if (is_digit == -1)
	{
		fprintf(stderr, "L%u: usage push integer \n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}

	/* get absolute value, no deal with overflows */
	number = atoi(line);

	/* insert node at the beginning */
	add_dnodeint(stack, number);

}

/**
 * pall- print the stack
 * @stack: dubble linked list
 * @line_number: the line at this number
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *ptr;

	size_t size = 0;

	ptr = *stack;
	while (ptr)
	{
		size++;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
	free(ptr);
}

/**
 * pint- print the first element of stack
 * @stack: stack
 * @line_number: number of the line used as command
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop- remove element on top of the stack
 * @stack: stack
 * @line_number: number of the line used as command
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: Can't pop from an empty stack \n", line_number);
		free_all(arg.stack_head);
		exit(EXIT_FAILURE);
	}
	del_dnodeint_index(stack, 0);
}

/**
 * swap- function that switch two element on top of stack
 * @stack: stack
 * @line_number: number of the line used as command
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int value;

	/* if no stack or only one in stack */
	if ((!stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(arg.stack_head);
		exit(EXIT_FAILURE);
	}

	/* stokk first value*/
	value = (*stack)->n;
	/* value one first become value of next */
	(*stack)->n = (*stack)->next->n;
	/* value of next become value of first stokked in tmp */
	(*stack)->next->n = value;
}



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
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
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

