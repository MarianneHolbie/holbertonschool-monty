#include "monty.h"

/**
 * check_arg- check if string is digit
 * @s: string to test
 *
 * Return: 1 if number, -1 otherwise
 */

int check_arg(char *s)
{
	int index = 0;

	/* if no string */
	if (!s)
		return (-1);

	/* while we have char in the string */
	while (s[index])
	{
		/* test if it is digit */
		if (s[index] >= '0' && s[index] <= '9')
			index++;
		else
			return (-1);
	}
	return (1);
}

/**
 * add_dnodeint- add value at the top of the stack
 * @head: head of stack
 * @n: value to add
 *
 * Return: new_node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	/* create new node */
	stack_t *new_node = NULL;

	/* allocate space  & test */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	/* add value */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	/* new head */
	if (*head)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}


/**
 * free_all- function that free stack and close file
 * @head : head of stack
 */

void free_all(stack_t *head)
{
	stack_t *tmp;

	/* free the stack */
	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}

	/* close file */
	if (arg.fp)
		fclose(arg.fp);
}

/**
 * del_dnodeint_index- delete stack at index
 * @head: head of stack
 * @index: place of node to delete
 *
 * Return: 1 if success, -1 failed
 */

int del_dnodeint_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	unsigned int count = 0;

	tmp = (*head);

	if (*head == NULL)
		return (-1);

	for (count = 0; tmp != NULL && count < index; count++)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (-1);

	if (*head == NULL || tmp == NULL)
		return (-1);

	if (*head == tmp)
		*head = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	free(tmp);
	return (1);
}
