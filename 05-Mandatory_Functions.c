#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @LN:unuseful variable in this function.
 * Return: void.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int LN)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_all - Adds a node to the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number of  the opcode.
 * Return: void
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * print_one - Prints the top node of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: the line number of of the opcode.
 * Return: void
 */
void print_one(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * remove_top - removes the top element of the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: void
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
