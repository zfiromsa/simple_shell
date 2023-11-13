#include "main.h"

void exec_list(_str_list *head, char **envp)
{
    _str_list *tmp;
    int num_cmd;
    char **args;
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    tmp = head;
    num_cmd = 0;
    while (tmp != NULL)
    {
        num_cmd++;
        tmp = tmp->next;
    }
    args = malloc((num_cmd) * sizeof(char *));
    if (args == NULL)
    {
        perror("Error");
        exit(98);
    }
    tmp = head;
    num_cmd = 0;
    while (tmp != NULL)
    {
        args[num_cmd] = tmp->cmd_list;
        num_cmd++;
        tmp = tmp->next;
    }
    if (execve(argv[0], argv, envp) == -1)
    {
        perror("Error:");
    }
    free(args);
}

