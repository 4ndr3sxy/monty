#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/** QUESTION
on ta monty

**/
int main(int argc, char *argv[])
{
    stack_t *stackMonty;
    stackMonty  = NULL;
    FILE *fp;
    char *tokenize[1024];
    char *c = NULL;
    unsigned int line = 1;
    size_t sizeC = 0;
    void (*cp_get_op_code)(stack_t **stack, unsigned int line);

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");

    //NOT important
    int i = 0;
    while (getline(&c, &sizeC, fp) != -1)
    {
        tokenize[i] = strtok(c, " ");
        i++;
        while (c != NULL)
        {
            c = strtok(NULL, " ");
            tokenize[i] = c;
            i++;
        }
        int j = 0;
        while(1)
        {
            cp_get_op_code = (*get_op_code)(tokenize[j]);//toquenizar dentro?
            if (cp_get_op_code)
            {
                break;
            }
            else
            {
                if (!tokenize[j + 1])
                {
                    break;
                }
                j++;
            }

        }
        (*cp_get_op_code)(&stackMonty, line);

        line++;
        i = 0;
    }
    fclose(fp);
    //END NOT important

    return (0);
}
