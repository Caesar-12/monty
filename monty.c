#include "monty.h"

/**
 * main - Monty byte code interpter
 *
 * @argc: arguments count
 * @argv: cl arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *mstack;
	FILE *fptr;
	char *fname;

	mstack = NULL;
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fname = (argv[1]);
	fptr = fopen(fname, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	fclose(fptr);
	get_func(argv[1], mstack);

	return (0);
}
