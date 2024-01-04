#include "monty.h"

/**
 * add_node - function that adds a new node at the begging of a list.
 * @stack: header of the list.
 * @n: number to insert in the list.
 *
 * Return: the addres of new node, or NULL if if failed
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = NULL;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	return (new);
}

/**
 * _isdigit - checks that a string only contains digits
 * @num: string to check
 *
 * Return: 0 if only digits, else 1
 */
int _isdigit(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (num[i] == '-' && i == 0)
			continue;
		if (isdigit(num[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * free_stack - frees node
 * @status: exit status
 * @arg: pointer to first node
 */
void free_stack(int status, void *arg)
{
	stack_t **tmp, *aux;

	(void)status;
	tmp = (stack_t **)arg;
	while (*tmp)
	{
		aux = (*tmp)->next;
		free(*tmp);
		*tmp = aux;
	}
}

/**
 * list_len - number of elements in a double linked list
 * @stack: pointer to first node
 *
 *Return: number of elements
 */

int list_len(stack_t **stack)
{
	stack_t *head;
	int i = 0;

	head = *stack;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}