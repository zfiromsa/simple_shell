#include "main.h"

/**
 * main - simpel shell
 *
 * Return: 0
 */
int main(void)
{
	int _status;
	char *cmds, **list_cmds;

	_status = 1;
	cmds = NULL;
	list_cmds = NULL;
	while (_status != -1)
	{
		printf("($) ");
		if (cmds = read_cmd(cmds))
		{
			return (0);
		}
		if (strlen(cmds) == 1 || cmds == NULL)
		{
			free(cmds);
			continue;
		}
		list_cmds = Func_list_cmds(cmds, list_cmds);
		free(cmds);
		if (list_cmds == NULL || list_cmds[0] == NULL)
		{
			free(cmds);
			break;
		}
		_status = execute(list_cmds);
		_free(list_cmds);
	}
	return (0);
}

