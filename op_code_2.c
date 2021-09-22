#include "monty.h"

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
