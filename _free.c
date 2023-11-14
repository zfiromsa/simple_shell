#include "main.h"

void _free(char **list_cmds)
{
    int i, j;

    i = 0;
    j = 1;
    list = NULL;
    while (list_cmds[i] != NULL)
    {
        list_cmds[j] = list_cmds[i];
        free(list_cmds[i]);
        i++;
        j++;
    }
    free(list_cmds);
}

