#include "monty.h"

/**
 * add_nodes - Add node the top two elements of the stack.
 * @stack: Pointer to a pointer  to top node of the stack.
 * @line_number:  the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * do_nothing - Does nothing.
 * @stack: unuseful variable in this function.
 * @line_number: unuseful variable in this function.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
