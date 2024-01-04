#include "monty.h"
/**
 * op_div - divides the second top element by the top element of the stack.
 * @stack: stack
 * @index: index number
 * Return: void
 */
void op_div(stack_t **stack, unsigned int index)
{
	stack_t *head = *stack;
	int count = 0, n1 = 0, n2 = 0;

	count = list_len(stack);
	if (count < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", index);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;

	if (n1 == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", index);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = n2 / n1;

	head = (*stack)->next;
	free(*stack);
	head->prev = NULL;
	(*stack) = head;
}