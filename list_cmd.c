#include "main.h"

char **Func_list_cmds(char *cmds, char **list_cmds)
{
    int BUFFER, i;
    char *token;

    BUFFER = 1024;
    i = 1;
    list_cmds = malloc(BUFFER * sizeof(char *));
    if (list_cmds == NULL)
    {
        perror("Error ");
        return (NULL);
    }
    token = strtok(cmds, " ");
    list_cmds[0] = token;
    printf("lidt 0:  %s\n", list_cmds[0]);
    printf("token 0:  %s\n", token);
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        if (list_cmds == NULL)
        {
            perror("Error func");
            break;
        }
        list_cmds[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    list_cmds[i] = "NULL";
    return (list_cmds);
}

