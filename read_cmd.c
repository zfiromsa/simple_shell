#include "main.h"

/**
 * read_cmd - it read from stdin store to a gaven parmet
 *
 * @cmds: pointer hold the address of string
 * Return: address of string
 */
char *read_cmd(char *cmds)
{
	size_t len;
	ssize_t rd;

	len = 0;
	rd = getline(&cmds, &len, stdin);
	if (rd == -1)
	{
		perror("Error read");
		free(cmds);
		exit(1);
	}
	return (cmds);
}

