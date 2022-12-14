#include "monty.h"

/**
 * intp_monty- open file, read and stock command by line
 *
 */

void intp_monty(void)
{
	char line[128];

	/* return of fopen : FILE pointer */
	arg.fp = fopen(arg.argv[1], "r");

	/* test fp */
	if (arg.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg.argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* read each line of file argv[1] */
		while (fgets(line, sizeof(line), arg.fp) != NULL)
		{
			arg.n_line++; /* count line */
			arg.line = line; /* stock line */
			cmp_op(); /* search function associate with cmd of the line */
		}
		/* close file */
		fclose(arg.fp);
	}
}

/**
 * cmp_op- compare struct cmd with line
 *
 */

void cmp_op(void)
{

	int i = 0; /* to move in list of op */
	char *cmdop = NULL; /* to get op in the line */

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		/*{"pint", pint},*/
		/*{"pop", pop},*/
		/*{"swap", swap},*/
		/*{"add", add},*/
		/*{"nop", nop},*/
		{NULL, NULL},
	};

	/* split line to give the name of op command */
	cmdop = strtok(arg.line, " \n");

	/* compare cmd_op with all instruction */
	while (op[i].opcode != NULL && cmdop)
	{
		if (!strcmp(cmdop, op[i].opcode))
		{
			op[i].f(&(arg.stack_head), arg.n_line);
			return;
		}
		i++;
	}

	/* if is not an monty instruction */
	fprintf(stderr, "L%d: unknown instruction %s", arg.n_line, cmdop);
	free_all(arg.stack_head);
	exit(EXIT_FAILURE);
}
