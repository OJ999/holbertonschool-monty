#include "monty.h"

/**
 * close_file - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void close_file(int status, void *arg)
{
	FILE *fp;

	(void)status;

	fp = (FILE *) arg;
	fclose(fp);
}