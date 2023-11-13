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

typedef struct str_list
{
char *cmd_list;
struct str_list *next;
} _str_list;

_str_list **lists_cmd(char *cmd, _str_list **cmds);
void free_list(_str_list **head);
void exec_list(_str_list *head, char **envp);
_str_list *add_nodeint_end(_str_list **head, char *cmd);

#endif

