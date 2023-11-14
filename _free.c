#include "main.h"

void _free(char **list_cmds)
{
    char **list;
    int i;

    i = 0;
    list = NULL;
    while (list_cmds[i] != NULL)
    {
        list = &list_cmds;
        free(list_cmds[i]);
        i++;
    }
    free(list_cmds);
}

