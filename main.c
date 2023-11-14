#include "main.h"

int main(int argc, char **argv, char **env)
{
    int _status, i;
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
        i = 0;
        list_cmds = Func_list_cmds(cmds, list_cmds);
        if (list_cmds == NULL)
        {
            perror("main Error ");
            break;
        }
        i = 0;
        while (list_cmds[i])
        {
            printf("%d:  %s\n", i, list_cmds[i]);
            i++;
        }
        _status = execute(list_cmds, env);
    }
    return (0);
}

