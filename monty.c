#include "monty.h"

arg_t arg;

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: array of argc
 * Return: EXIT_SUCCESS on exit, EXIT_FAILURE otherwise
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* initialize struct arg_t */
	arg.argv = argv;
	arg.n_line = 0;
	arg.line = NULL;
	arg.stack_head = NULL;
	arg.fp = NULL;

	/* call interpreter */
	intp_monty();

	return (EXIT_SUCCESS);
}
