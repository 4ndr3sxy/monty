#include "monty.h"

global_t dataStruct;
/** QUESTION
on ta monty

**/
void change_last_character(char *line)
{
    int i = 0;
    while (line[i] != '\n')
    {
        i++;
    }
    line[i] = '\0';
}

int main(int argc, char *argv[])
{

    void (*cp_get_op_code)(stack_t * *stack, unsigned int line);
    FILE *fp = NULL;
    char *c = NULL;
    unsigned int line = 1;
    size_t sizeC = 0;
    stack_t *stackMonty = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    while ((int)getline(&c, &sizeC, fp) != -1)
    {
        change_last_character(c);
        dataStruct.lineTokenized = c;
        if (c[0] != '#')
        {
            /* printf("main %s", c); */
            cp_get_op_code = (*get_op_code)();
            if (cp_get_op_code)
            {
                /*printf("4. MAIN\n");*/
                (*cp_get_op_code)(&stackMonty, line);
            }
        }
        line++;
    }
    free(c);
    fclose(fp);
    free_dlistint(stackMonty);

    return (0);
}
