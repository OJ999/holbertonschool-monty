#include "monty.h"
/**
 * op_add - adds the top two count of the stack.
 * @stack: double pointer to the head of the list
 * @index: line index
 * Return: void
 */
void op_add(stack_t **stack, unsigned int index)
{
	stack_t *head = *stack;
	int count = 0, n1 = 0, n2 = 0;

	count = list_len(stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", index);
		exit(EXIT_FAILURE);
	}
	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	(*stack)->next->n = n1 + n2;

	head = (*stack)->next;
	head->next = (*stack)->next->next;
	free(*stack);
	head->prev = NULL;
	(*stack) = head;
}