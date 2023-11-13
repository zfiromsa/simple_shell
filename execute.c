#include "main.h"

int execute(char **list_cmds,char **env)
{
    pid_t pid;
    int status, i;

    pid = fork();
    if (pid == -1)
    {
        perror("Error ");
    }
    if (pid == 0)
    {
        if (execve(list_cmds[0], list_cmds, env) == -1)
        {
            perror("Error ");
            exit(1);
        }
    }
    else
    {
        i = 0;
        while (list_cmds[i])
        {
            printf("%d:  %s\n", i, list_cmds);
            i++;
        }
        wait(&status);
    }
    free(list_cmds);
    return (1);
}

