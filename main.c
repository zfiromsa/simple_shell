#include "main.h"

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
        read_cmd(cmds);
        _status = Func_list_cmds(cmds, list_cmds);
        _status = execute(list_cmds, env);
    }
    return (0);
}

