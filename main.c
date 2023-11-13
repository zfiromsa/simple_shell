#include "main.h"

int main(int argc, char **argv, char **env)
{
    int status, BUFFER;
    char *cmds, **list_cmds;


    status = 0;
    cmds = NULL;
    list_cmds = NULL;
    (void)argv;
    (void)argc;
    while (status)
    {
        printf("($) ");
        read_cmd(cmds);
        status = Func_list_cmds(cmds, list_cmds);
        status = execute(list_cmds, env);
    }
    return (0);
}

