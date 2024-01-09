#include "monty.h"

/**
 * print_string - task 12: prints the string starting
 * at the top of the stack, followed by a new line.
 * @stack: Pointer to a pointer  to top node of the stack.
 * @LN: the line number of of the opcode.
 *
 * Return: void
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int LN)
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
