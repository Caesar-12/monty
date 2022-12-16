#include "monty.h"

/**
 * get_func - matches opcode with corresponding function
 *
 * @filename: File name
 * @stack: Dlist stack
 *
 * Return: void
 */

void get_func(char *filename, stack_t *stack)
{
	instruction_t functs[] = {
		{"push", stack_push},
		{"pall", stack_pall}
	};
	FILE *monty_file;
	char *instruct, *record, *token, *data;
	int trav;
	ssize_t count;
	size_t size = 10;
	unsigned int line_num, num;

	instruct = NULL;
	monty_file = fopen(filename, "r");
	line_num = 1;
	while ((count = getline(&instruct, &size, monty_file)) != -1)
	{
		record = instruct;
		token = strtok(record, " \n\t");
		for (trav = 0; trav < 2;)
		{
			if ((strcmp(token, functs[trav].opcode)) == 0)
			{
				if (trav < 1)
				{
					data = (char *)strtok(NULL, " \n\t");
					num = atoi(data);
					if ((isdigit(num)) == 0)
					{
						num = (unsigned int)(num);
						functs[trav].f(&stack, num);
						trav = 0;
						break;
					}
					else
					{
						fprintf(stderr, "L%d: : usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}
				}
				else if (trav >= 1)
				{
					functs[trav].f(&stack, line_num);
					trav = 0;
					break;
				}
				printf("trav = %d\n", trav);
			}
			else if (trav == 2)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token);
				exit(EXIT_FAILURE);
			}
			trav++;
		}
		line_num++;
	}
}
