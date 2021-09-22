#include "monty.h"

/**
 * op_push - add new node to linked list
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: Returnless
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	line_number = 0;

	add_dnodeint(stack, dataStruct.dataToSave);
}

/**
 * op_pall - print a linked list
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: Returnless
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

/**
 * op_pint - print node in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
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

/**
 * op_pop - delete node in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	line_number = 0;

	delete_dnodeint_at_index(stack, 0);
}

/**
 * op_swap - swap the 2 nodes in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
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
