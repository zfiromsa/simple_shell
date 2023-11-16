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

	len = 0;
	getline(&cmds, &len, stdin);
	return (cmds);
}

