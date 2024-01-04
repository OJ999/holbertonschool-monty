#include "monty.h"

/**
 * op_pall - function that print the content of a list.
 * @stack: pointer to the head of the list.
 * @index_line: line index
 * Return: nothing
 */
void op_pall(stack_t **stack, unsigned int index_line)
{
	stack_t *head = *stack;
	(void)index_line;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	return; /* check this */
}