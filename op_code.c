#include "monty.h"

/**
 * op_add - add two numbers
 * @a: firts number.
 * @b: second number.
 * Return: add
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	printf("5. %d\n", line_number);
    	printf("6. ANDRÉS ESTUVO AQUí \n");
}

/**
 * print_list - prints all elements of a list.
 * @h: pointer to header of linked list.
 *
 * Return: Number of nodes.
 */
void op_pall(stack_t **stackMonty, unsigned int line)
{
	printf("7. ENTRÉ");
	stack_t *temp = *stackMonty;
	unsigned int i = line;
	printf("line %d & stack %d \n", line, temp->n);

    /*
	while (*stackMonty)
	{
		printf("%d\n", stackMonty->n);
		stackMonty = stackMonty->next;
		i++;
	}
    */
}