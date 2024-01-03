#include "monty_headerflie.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_number:unuseful variable in this function.
 * Return: void.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_number)
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
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer to top node of the stack.
 * @line_number: line number of  the opcode.
 * Return: void
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}