#include "monty.h"

void op_pchar(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	printf("%c\n", (*stack)->n);
}

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
