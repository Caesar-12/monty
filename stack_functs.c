#include "monty.h"

/**
 * stack_push - Pushes element onto the stack
 *
 * @stack: Stack to push into
 * @line_num: data to push
 *
 * Return: void
 */

void stack_push(stack_t **stack, unsigned int line_num)
{
	stack_t *stacked, *top, *tail;
	int nodes, val;

	val = (int)(line_num);
	top = tail = *stack;
	if (!(top))
	{
		top = (stack_t *)malloc(sizeof(stack_t));
		top->prev = NULL;
		top->next = NULL;
		top->n = val;
		*stack = tail = top;
		return;
	}
	nodes = 0;
	while (tail->next)
	{
		tail = tail->next;
		nodes++;
	}
	stacked = (stack_t *)malloc(sizeof(stack_t));
	stacked->next = NULL;
	stacked->n = val;
	stacked->prev = tail;
	tail->next = stacked;
	tail = stacked;
}

/**
 * stack_pall - Prints int in a stack
 *
 * @stack: Stack to print data
 * @line_num: line number
 *
 * Return: void
 */

void stack_pall(stack_t **stack, unsigned int __attribute__((__unused__)) line_num)
{
	stack_t *trav, *tail, *chk;

	if (*stack == NULL)
		return;
	tail = *stack;
	while (tail->next)
		tail = tail->next;

	trav = tail;

	while (chk)
	{
		fprintf(stdout, "%d\n", trav->n);
		trav = trav->prev;
		chk = trav;
	}
}
