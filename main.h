#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

void read_cmd(char *cmds);
char **Func_list_cmds(char *cmds, char **list_cmds);
int execute(char **list_cmds,char **env);

#endif

