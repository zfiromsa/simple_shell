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
	char *cmds, **list_cmds;

	cmds = NULL;
	list_cmds = NULL;
	(void)argv;
	(void)argc;
	while (true)
	{
		printf("($) ");
		cmds = read_cmd(cmds);
		list_cmds = Func_list_cmds(cmds, list_cmds);
		if (list_cmds == NULL)
		{
			break;
		}
		execute(list_cmds, env);
		_free(list_cmds);
	}
	return (0);
}

