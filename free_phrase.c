#include "monty.h"

/**
 * free_phrase - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to arg
 *
 * Return: void
 */
void free_phrase(int status, void *arg)
{
	char **lineptr = arg;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
}