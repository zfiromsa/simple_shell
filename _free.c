#include "main.h"

void _free(char **list_cmds)
{
    int i;

    i = 0;
    while (list_cmds[i] != NULL)
    {
        free(list_cmds[i]);
        i++;
    }
    free(list_cmds);
}

