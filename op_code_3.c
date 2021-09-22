#include "monty.h"

/**
 * op_pchar - function to print the character on top of the list
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - function to print a string
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *copyHead = *stack;

	while (copyHead)
	{
		printf("%c", copyHead->n);
		if (copyHead->next->n == 0)
		{
			break;
		}
		copyHead = copyHead->next;
	}
	printf("\n");
}
