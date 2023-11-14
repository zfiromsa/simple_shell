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
		list_cmds = Func_list_cmds(cmds, list_cmds);
		printf("111111111");
		if (list_cmds == NULL)
		{
			printf("222222222222");
			break;
		}
		printf("3333333333333");
		_status = execute(list_cmds, env);
	}
	printf("44444444444");
	return (0);
}

