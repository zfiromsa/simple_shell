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


    _status = 1;
	i = 0;
	cmds = NULL;
	list_cmds = NULL;
	(void)argv;
	(void)argc;
	while (_status)
	{
		printf("($) ");
		cmds = read_cmd(cmds);
		list_cmds = Func_list_cmds(cmds, list_cmds);
		while (list_cmds[i])
		{
			printf("1111 %s\t\n", list_cmds[i]);
			i++;
		}
		if (list_cmds == NULL)
		{
			break;
		}
		execute(list_cmds, env);
	}
	_free(list_cmds);
	return (0);
}

