#include "monty.h"

/**
 * find_R_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * Return: void
 */
void find_R_function(char *opcode, char *value, int line_number, int format)
{
	int i;
	int j;

	instruction_t funcions_list[] = {
		{"push", add_to_stack},
		{"pall", print_all},
		{NULL, NULL}};

	for (j = 1, i = 0; funcions_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcions_list[i].opcode) == 0)
		{
			call_function(funcions_list[i].f, opcode, value, line_number, format);
			j = 0;
		}
	}
	if (j == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}

/**
 * call_function - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @LineN: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * Return: void
 */
void call_function(op_func func, char *op, char *value, int LineN, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value += 1;
			flag = -1;
		}
		if (value == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", LineN);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				fprintf(stderr, "L%d: usage: push integer\n", LineN);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, LineN);
		if (format == 1)
			add_node_to_queue(&node);
	}
	else
		func(&head, LineN);
}
