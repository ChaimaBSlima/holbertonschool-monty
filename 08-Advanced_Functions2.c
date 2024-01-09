#include "monty.h"

/**
 * print_string - task 12: prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: Pointer to a pointer  to top node of the stack.
 * @LineN: the line number of of the opcode.
 *
 * Return: void
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int LineN)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * reverse_nodes -  rotates the stack to the top.
 * at the top of the stack, followed by a new line.
 * @stack: Pointer to a pointer  to top node of the stack.
 * @LineN: the line number of of the opcode.
 *
 * Return: void
 */
void reverse_nodes(stack_t **stack, __attribute__((unused))unsigned int LineN)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
