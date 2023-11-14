#include "main.h"

char **Func_list_cmds(char *cmds, char **list_cmds)
{
    int i;
    char *token;

    i = 0;
    list_cmds = malloc(sizeof(char *));
    if (list_cmds == NULL)
    {
        perror("Error ");
        return (NULL);
    }
    token = strtok(cmds, " ");
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        list_cmds[i] = token;
        token = strtok(NULL, " ");
        i++;
        list_cmds = realloc(list_cmds, ((i + 1) * sizeof(char *)));
        if (list_cmds)
        {
            perror("Error func");
            break;
        }
    }
    list_cmds[i] = NULL;
    return (list_cmds);
}

