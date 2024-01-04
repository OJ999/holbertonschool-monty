#include "monty.h"

/**
 * op_swap - function to swap the values of the top elements of a linked list
 * @stack: double pointer to head of doubly linked list
 * @index_line: line number of the file
 *
 * Return: nothing.
 */
void op_swap(stack_t **stack, unsigned int index_line)
{
	stack_t *temp;
	int len = 0;

	len = list_len(stack);

	if (len < 2 || stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", index_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->prev = temp;
		(*stack)->next = temp->next;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
