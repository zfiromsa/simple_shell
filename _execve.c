#include "main.h"

void exec_list(_str_list *head)
{
    printf("kkkkkkkkk");
    _str_list *tmp;
    int num_cmd;
    char **args;

    tmp = head;
    num_cmd = 0;
    while (tmp != NULL)
    {
        num_cmd++;
        tmp = tmp->next;
    }
    args = malloc((num_cmd + 1) * sizeof(char *));
    if (args == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for args\n");
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
    args[num_cmd] = NULL;
    execve(args[0], args, NULL);
    free(args);
}

