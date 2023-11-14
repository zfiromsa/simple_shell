#include "main.h"

char **Func_list_cmds(char *cmds, char **list_cmds)
{
    int BUFFER, i;
    char *token;

    printf("11test:\t %s\n", cmds);
    BUFFER = 1024;
    i = 0;
    list_cmds = malloc(BUFFER * sizeof(char *));
    printf("22test:\t %s\n", cmds);
    if (list_cmds == NULL)
    {
        perror("Error ");
        return (NULL);
    }
    printf("33test:\t %s\n", cmds);
    token = strtok(cmds, " ");
    printf("test 1:\t %s\n", token);
    while (token != NULL)
    {
        if (token[0] == '#')
        {
 printf("test 2:\t %s\n", token);
            break;
        }
        if (strcmp(token, "exit") || strcmp(token, "EXIT"))
        {
 printf("test 3:\t %s\n", token);
            return (0);
        }
        list_cmds[i] = strdup(token);
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

