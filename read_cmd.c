#include "main.h"

void read_cmd(char *cmds)
{
    size_t len;
    ssize_t rd;

    len = 0;
    rd = getline(&cmds, &len, stdin);
 printf("test read:\t %s\n", cmds);
    if (rd == -1)
    {
        perror("Error ");
        free(cmds);
        exit(1);
    }
}
