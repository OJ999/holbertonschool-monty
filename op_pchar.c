#include "monty.h"

/**
 * op_pchar - function to print the char value at the top of a stack
 * @stack: double pointer of stack_t type to head of stack
 * @index_line: unsigned int for line number
 * Return: print the value at the first element of stack
 */
void op_pchar(stack_t **stack, unsigned int index_line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", index_line);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n > 64 && (*stack)->n < 91) || ((*stack)->n > 96 &&
						       (*stack)->n < 123))
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", index_line);
		exit(EXIT_FAILURE);
	}
}