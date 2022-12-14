#include "monty.h"

/**
 *  is_digit - check string
 * @string: char
 *
 * Return: 1
 */
int is_digit(char *string)
{
	int n = 0;

	if (!string)
		return (-1);

	while (string[n])
	{
		if (string[n] >= '0' && string[n] <= '9')
		{
			n++;
		}

		else
			return (-1);
	}
	return (1);
}

/**
 *  add_dnodeint - add node
 * @head: double pointer
 * @n: const int
 * Return: newnode
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "error malloc\n");
		free(newnode);
		exit(EXIT_FAILURE);
	}

	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = newnode;

	(*head) = newnode;
	return (newnode);
}

/**
 *  del_nodeint_index - delete node
 * @head: double pointer
 * @index: unsigned int
 * Return:
 */

int *del_dnodeint_index(stack_t **head, unsigned int index)
{
	stack_t *tmp = *head;

	if (!tmp)
		return (0);

	else
	{
		index = (*head)->n;
		*head = tmp->next;
	}
	free(tmp);
	return (0);
}

/**
 *  del_nodeint_index - delete node
 * @head: double pointer
 * @index: unsigned int
 * Return:
 */

void free_all(stack_t *head)
{
	stack_t *tmp;

	tmp = head;

	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
	if (arg.fp)
		fclose(arg.fp);
}
