#include "monty.h"

/**
 * get_op_func - functi to select operations
 * @s: character to validate simbol
 * Return: int
 */
void (*get_op_code(char *s))(stack_t **stack, unsigned int line)
{
    int i = 0, j = 0, validator = 0;
    instruction_t opCodes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {NULL, NULL}};

    while (i < 2)
    {
        while (s[j])
        {
            validator = digit_check(s[j + 1]);
            if (*opCodes[i].opcode == s[j] && validator)
            {
                printf("SIUUU\n");
                return (opCodes[i].f);
            }
            j++;
        }
        j = 0;
        i++;
    }
    printf("EFE\n");
    return (NULL);
}
