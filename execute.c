#include "main.h"

int execute(char **list_cmds,char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Error ");
    }
    if (pid == 0)
    {
        execve(list_cmds[0], list_cmds, env);
    }
    else
    {
        wait(&status);
    }
    free(list_cmds);
    return (0);
}

