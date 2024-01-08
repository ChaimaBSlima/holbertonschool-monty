#include "monty.h"

/**
 * sub_nodes - task 6: subtracts the top element of the stack
 * @stack: Pointer to a pointer  to top node of the stack.
 * @line_number: the line number of of the opcode.
 *
 * Return: void
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - task 7: divides the second top element of the stack
 *  by the top element of the stack.
 * @stack: Pointer to a pointer  to top node of the stack.
 * @line_number: the line number of of the opcode.
 *
 * Return: void
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
