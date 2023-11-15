#include "main.h"

/**
 * main - simpel shell
 *
 * @argc: parm
 * @argv: parm
 * @env: enviroment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	int _status, i;
	char *cmds, **list_cmds;

	i = 0;
    _status = 1;
	cmds = NULL;
	list_cmds = NULL;
	(void)argv;
	(void)argc;
	while (_status != -1)
	{
		printf("($) ");
		cmds = read_cmd(cmds);
		if (strlen(cmds) == 1)
		{
			free(cmds);
			continue;
		}
		list_cmds = Func_list_cmds(cmds, list_cmds);
		if (list_cmds == NULL || list_cmds[0] == NULL)
		{
			free(cmds);
			break;
		}
		while (list_cmds[i])
		{
		printf("%i:   %s\n", i, list_cmds[i]);
		i++;
		printf("%i:\n", i);
		}
		printf("%i:   %s\n", i, list_cmds[i]);
		_status = execute(list_cmds, env);
		_free(list_cmds);
		free(cmds);
	}
	return (0);
}

