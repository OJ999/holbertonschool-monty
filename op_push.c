#include "monty.h"
/**
 * op_push - push an integer onto the stack
 * @stack: double pointer to the beginning of the dll.
 * @index_line: script line number
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int index_line)
{
	char *num = NULL;
	int n;

	num = strtok(NULL, "\n\t\r ");
	if (num == NULL || _isdigit(num))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", index_line);
		exit(EXIT_FAILURE);
	}
	n = atoi(num);
	if (!add_node(stack, n))
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}