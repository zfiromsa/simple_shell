#include "main.h"

char **Func_list_cmds(char *cmds, char **list_cmds)
{
    int BUFFER, i;
    char *token;

    BUFFER = 1024;
    i = 0;
    list_cmds = malloc(BUFFER * sizeof(char *));
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
        if (strcmp(token, "exit") || strcmp(token, "EXIT"))
        {
            return (0);
        }
        strcpy(list_cmds[i],token);
        token = strtok(NULL, " ");
        i++;
    }
    free(cmds);
    return (list_cmds);
}

