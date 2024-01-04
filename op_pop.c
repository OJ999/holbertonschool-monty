#include "monty.h"
/**
 * op_pop - removes the top element of the stack.
 * @stack: double pointer to head of the list
 * @index_line: line index
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int index_line)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", index_line);
		exit(EXIT_FAILURE);
	}
	*stack = head->next;
	if (head->next)
		head->next->prev = NULL;
	free(head);
}
