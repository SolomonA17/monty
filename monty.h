#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Structure representing a node in a doubly linked list.

 * @field n: The data stored within the node (e.g., integer value, data pointer).
 * @field prev: Pointer to the previous node in the linked list.
 * @field next: Pointer to the next node in the linked list.

 * Description: This structure can be used to build both stacks and queues
 * through appropriate manipulation of `prev` and `next` pointers. It supports
 * both LIFO (Last In First Out) and FIFO (First In First Out) access depending
 * on the implementation of the data structure.
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * Structure representing an instruction in the program.

 * @field opcode: The identifier or code defining the desired operation (e.g., string keyword, integer value).
 * @field f: Pointer to the function responsible for handling the specific opcode. This function typically takes the instruction structure and other relevant context as arguments.

 * Description: This structure associates an opcode with its corresponding function handler. 
 * The program uses this mapping to determine the appropriate action to take for each encountered instruction. 
 * The opcode can define operations for manipulating data structures like stacks and queues, 
 * influencing their behavior (e.g., pushing/popping elements, implementing LIFO/FIFO access).

 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*String operations*/
void rotl(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
void find_func(char *, char *, int, int);
void read_file(FILE *);
int len_chars(FILE *);
int parse_line(char *buffer, int line_number, int format);

/*Error hanlding*/
void err(int error_code, ...);
void rotr(stack_t **, unsigned int);
void string_err(int error_code, ...);
void more_err(int error_code, ...);

void call_fun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);


#endif
