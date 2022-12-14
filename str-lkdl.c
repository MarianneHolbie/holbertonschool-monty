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
		free_all(arg.stack_head);
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
 * free_all- free stack
 * @head: double pointer
 *
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

	/* close file */
	if (arg.fp)
		fclose(arg.fp);
}

/**
 * free_dlist- free double linked list
 * @head: head of double linked list
 * 
 */

void free_dlist(stack_t *head)
{
	stack_t *tmp = head;

	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
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
