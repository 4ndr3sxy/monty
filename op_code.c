#include "monty.h"

/**
 * op_add - add two numbers
 * @a: firts number.
 * @b: second number.
 * Return: add
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	/*printf("En push\n");*/
	line_number = 0;
	add_dnodeint(stack, dataStruct.dataToSave);
}

/**
 * print_list - prints all elements of a list.
 * @h: pointer to header of linked list.
 *
 * Return: Number of nodes.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *copyHead = *stack;

	while (copyHead)
	{
		printf("%d\n", copyHead->n);
		copyHead = copyHead->next;
	}
}

void op_pint(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *copyHead = *stack;

	while (copyHead)
	{
		printf("%d\n", copyHead->n);
		break;
	}
}

void op_pop(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	delete_dnodeint_at_index(stack, 0);
}

void op_swap(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *copyHead = *stack;
	stack_t *temp = copyHead->next;
	copyHead->next = copyHead->next->next;
	copyHead->prev = copyHead->next->prev;
	temp->next = copyHead;
	temp->prev = NULL;
	*stack = temp;
}


/* Other file */
void op_add(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

void op_sub(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

void op_div(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

void op_mul(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

void op_mod(stack_t **stack, unsigned int line_number)
{
	line_number = 0;
	stack_t *temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


/* Other file  */
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
