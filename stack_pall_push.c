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
	/*il me manque une condition ici aussi je pense*/
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
	stack_t *newnode;
	int n;

	(void)(line_number);

	/*il me manque une condition je pense*/

	newnode->n = n;
	newnode->next = *stack;
	newnode->prev = NULL;

	if ((*stack) != NULL)
		(*stack)->prev = newnode;

	(*stack) = newnode;
	return (newnode);
}

/*et je dois rajouter un isdigit pour verifier si c'est un integer */
