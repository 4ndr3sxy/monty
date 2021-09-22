#include "monty.h"
#include <stdio.h>

/**
 * get_op_func - functi to select operations
 * @s: character to validate simbol
 * Return: int
 */
void (*get_op_code())(stack_t **stack, unsigned int line)
{
    int i = 0, j = 0;
    int val = 0;
    char *tokenize[1024];
    instruction_t opCodes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {"pop", op_pop},
        {"pint", op_pint},
        {"swap", op_swap},
        {"add", op_add},
        {"sub", op_sub},
        {"div", op_div},
        {"mul", op_mul},
        {"mod", op_mod},
        {"pchar", op_pchar},
        {"pstr", op_pstr},
        {NULL, NULL}};

    tokenize_line(dataStruct.lineTokenized, tokenize);

    while (i < 12)
    {
        j = 0;
        while (tokenize[j])
        {
            //printf("%s == %s\n",opCodes[i].opcode, tokenize[j]);
            /*if (opCodes[i].opcode == tokenize[j])*/

            if (strcmp(opCodes[i].opcode, tokenize[j]) == 0)
            {

                //printf("3. SIUUU\n");
                //printf("dataToSAve = %s\n", tokenize[j + 1]);

                if (tokenize[j + 1])
                    val = atoi(tokenize[j + 1]);

                dataStruct.dataToSave = val;
                //printf("¡¡¡dataToSAve = %d\n", dataStruct.dataToSave);
                return (opCodes[i].f);
            }
            j++;
        }
        i++;
    }
    /*printf("3. EFE\n");*/
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
    //printf("Esto es line %s", line);
    tokenize[i] = strtok(line, " ");
    i++;
    while (line != NULL)
    {
        line = strtok(NULL, " ");
        tokenize[i] = line;
        i++;
    }
}
