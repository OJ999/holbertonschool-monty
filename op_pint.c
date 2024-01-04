#include "monty.h"

/**
 * op_pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @index_line: line number of current operation
 *
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int index_line)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", index_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}