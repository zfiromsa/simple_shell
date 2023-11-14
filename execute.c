#include "main.h"

int execute(char **list_cmds,char **env)
{
    pid_t pid;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    pid = fork();
    (void)list_cmds;
    if (pid == -1)
    {
        perror("Error ");
    }
    if (pid == 0)
    {
        if (execve(argv[0], argv, env) == -1)
        {
            perror("Error - ");
            return (0);
        }
    }
    else
    {
        wait(&status);
    }
    _free(list_cmds);
    return (1);
}

