#include "monty.h"

/**
 * op_mul - function that multiply
 * @stack: double pointer of stack_t type to head of stack
 * @index_line: unsigned int type
 * Return: stack with new sum and removed node
 *
 */
void op_mul(stack_t **stack, unsigned int index_line)
{
	stack_t *temp = *stack;
	int len = 0;

	len = list_len(stack);
	if (len < 2 || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", index_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp->next->n *= (*stack)->n;
		*stack = (*stack)->next;
		free(temp);
		(*stack)->prev = NULL;
	}
}