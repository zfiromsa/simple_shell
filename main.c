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
	int _status;
	char *cmds, **list_cmds;


	_status = 1;
	cmds = NULL;
	list_cmds = NULL;
	(void)argv;
	(void)argc;
	while (_status)
	{
		printf("($) ");
		cmds = read_cmd(cmds);
		if (cmds == NULL)
		{
			return (0);
		}
		list_cmds = Func_list_cmds(cmds, list_cmds);
		if (list_cmds == NULL)
		{
			perror("main Error ");
			break;
		}
		_status = execute(list_cmds, env);
	}
	return (0);
}

