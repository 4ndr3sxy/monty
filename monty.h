#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @dataToSave: data to strack or queue
 * *@lineTokenized: Data extract from FILE
 *
 * Description: struct to save global info
 */
typedef struct global_s
{
    int *dataToSave;
    char *lineTokenized;
    
} global_t;

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

void op_push(stack_t **stack, unsigned int line_number);

void op_pall(stack_t **stack, unsigned int line_number);

void (*get_op_code(global_t *dataStruct))(stack_t **stack, unsigned int line);

int digit_check(char *key);

void tokenize_line(char *line, char **tokenize);
#endif /* MONTY_H */
