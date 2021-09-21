#include "monty.h"
#include <stdio.h>

/**
 * get_op_func - functi to select operations
 * @s: character to validate simbol
 * Return: int
 */
void (*get_op_code(char *s))(stack_t **stack, unsigned int line)
{
    int i = 0, j = 0;
    char *tokenize[1024];
    instruction_t opCodes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {NULL, NULL}};
    tokenize_line(s, tokenize);
    
    while (i < 2)
    {
        j = 0;
        while (tokenize[j])
        {
            if (*opCodes[i].opcode == *tokenize[j])
            {
                printf("SIUUU\n");
                return (opCodes[i].f);
            }
            j++;
        }
        i++;
    }
    printf("EFE\n");
    return (NULL);
}

void tokenize_line(char *line,char **tokenize)
{
    int i = 0;

    tokenize[i] = strtok(line, " ");
    i++;
    while (line != NULL)
    {
        line = strtok(NULL, " ");
        tokenize[i] = line;
        i++;
    }
}
