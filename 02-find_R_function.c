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
		{"push", add_to_stack}, {"pall", print_all},
		{"pint", print_one}, {"pop", remove_top},
		{"swap", swap_nodes}, {"add", add_nodes},
		{"nop", do_nothing},
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
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
