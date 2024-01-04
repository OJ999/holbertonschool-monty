#include "monty.h"

/**
  * main - main function
  * @argc: number of arguments
  * @argv: arguments
  *
  * Return: Always 0 on success
  */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int index_line = 0;
	FILE *fp = NULL;
	char *phrase = NULL, *instruct = NULL;
	size_t n = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_phrase, &phrase);
	on_exit(free_stack, &stack);
	on_exit(close_file, fp);
	while (getline(&phrase, &n, fp) != -1)
	{
		index_line++;
		instruct = strtok(phrase, "\n\t\r ");
		if (instruct != NULL && instruct[0] != '#')
		{
			get_instruct(instruct, &stack, index_line);
		}
	}
	/*free(phrase);*/
	/*free_list(stack);*/
	/*fclose(fp);*/
	exit(EXIT_SUCCESS);
}