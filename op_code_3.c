#include "monty.h"

/**
 * op_pchar - function to print the character on top of the list
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	dataStruct.valDataToSave = 0;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	if ((*stack)->n < 0 || (*stack)->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
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
	stack_t *copyHead = NULL;
	(void)line_number;
	dataStruct.valDataToSave = 0;

	if ((*stack))
		copyHead = *stack;
	while (copyHead)
	{
		printf("%c", copyHead->n);
		if (copyHead->next->n == 0
		|| copyHead->next->n < 0 || copyHead->next->n > 255)
		{
			break;
		}
		copyHead = copyHead->next;
	}
	printf("\n");
}
