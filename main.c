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
		list_cmds = Func_list_cmds(cmds, list_cmds);
		if (list_cmds == NULL)
		{
			break;
		}
		while (list_cmds[i])
		{
		printf("%i:   %s\n", i, list_cmds[i]);
		i++;
		}
		printf("%i:   %s\n", i, list_cmds[i]);
		execute(list_cmds, env);
	}
	free(cmds);
	_free(list_cmds);
	return (0);
}

