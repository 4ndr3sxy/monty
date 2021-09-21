#include "monty.h"
#include <stdio.h>

/**
 * get_op_func - functi to select operations
 * @s: character to validate simbol
 * Return: int
 */
void (*get_op_code(global_t *dataStruct))(stack_t **stack, unsigned int line)
{
    int i = 0, j = 0;
    char *tokenize[1024];
    instruction_t opCodes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {NULL, NULL}};
    tokenize_line(dataStruct->lineTokenized, tokenize);
    
    while (i < 2)
    {
        j = 0;
        while (tokenize[j])
        {
            if (*opCodes[i].opcode == *tokenize[j])
            {
                printf("1 . SIUUU\n");
                dataStruct->dataToSave = (int*)tokenize[j+1];
                /* printf("__&&%ls&&__\n", dataStruct->dataToSave); */
                printf("2. _%s_\n", opCodes[1].opcode); 
                return (opCodes[i].f);
            }
            j++;
        }
        i++;
    }
    printf("3. EFE\n");
    return (NULL);
}
/**
 * tokenize-line - get a line and save info to validate
 * *@line: character to validate symbol
 * **@tokenize: pointer array to save tokenized line
 * Return: void
 */
void tokenize_line(char *line, char **tokenize)
{
    int i = 0;
    /* printf("Esto es line %s", line); */
    tokenize[i] = strtok(line, " ");
    i++;
    while (line != NULL)
    {
        line = strtok(NULL, " ");
        tokenize[i] = line;
        i++;
    }
}
