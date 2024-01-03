#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*  make the head global variable */
extern stack_t *head;
/* function to operate */
typedef void (*op_func)(stack_t **, unsigned int);

/* Functions of the file 01-file_operations.c */
void open_file(char *file_name);
void read_file(FILE *fd);
int parse_line(char *buffer, int line_number, int format);

/* Functions of the file 02-functions_calls.c */
void find_R_function(char *opcode, char *value, int line_number, int format);
void call_function(op_func func, char *op, char *value, int line_number, int format);

/* Function of the file 03-node_operations.c */
stack_t *create_node(int n);
void free_nodes(void);
void add_node_to_queue(stack_t **new_node);

/* Function of the file 04-Mandatory_Functions.c */
void add_to_stack(stack_t **new_node, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H*/