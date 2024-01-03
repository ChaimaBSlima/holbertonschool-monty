#include "monty.h"
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
		{
			fprintf(stderr, "L%d: usage: push integer\n", LineN);
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", LineN);
				exit(EXIT_FAILURE);
			}
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
