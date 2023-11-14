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
 printf("test 3:\t %s\n", token);
            return (0);
        }
        strcpy(list_cmds[i], token);
 printf("test %d:\t %s\n", i, list_cmds[i]);
        if (list_cmds == NULL)
        {
            perror("Error func");
            break;
        }
        token = strtok(NULL, " ");
 printf("token test %d:\t %s\n", i, token);
        i++;
    }
    free(cmds);
    return (list_cmds);
}

