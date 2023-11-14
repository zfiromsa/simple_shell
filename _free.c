#include "main.h"
/**
 * _free - it free allocated space
 * @list_cmds: it is a poiter(address) of to free
 */
void _free(char **list_cmds)
{
	int i;

	i = 0;
 	while (list_cmds[i] != NULL)
	{
		free(list_cmds[i]);
		i++;
	}
	free(list_cmds);
}

