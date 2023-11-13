#include "main.h"

int Func_list_cmds(char *cmds, char **list_cmds)
{
    int BUFFER, i;
    char *token;

    BUFFER = 1024;
    i = 0;
    list_cmds = malloc(BUFFER * sizeof(char *));
    if (list_cmds)
    {
        perror("Error ");
        return (1);
    }
    token = strtok(cmds, " ");
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        if (strcmp(token, "exit") || strcmp(token, "EXIT"))
        {
            return (0);
        }
        list_cmds[i] = token;
        token = strtok(cmds, " ");
        i++;
    }
    free(cmds);
    return (1);
}

