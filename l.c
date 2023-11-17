
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

char *read_cmd(char *cmds);
char **Func_list_cmds(char *cmds, char **list_cmds);
int execute(char **list_cmds);
void _free(char **listcmds);


int main(void)
{
	int _status;
	char *cmds, **list_cmds;

	_status = 1;
	cmds = NULL;
	list_cmds = NULL;
	while (_status != -1)
	{
		printf("($) ");
		cmds = read_cmd(cmds);
		if (strlen(cmds) == 1 || cmds == NULL)
		{
			free(cmds);
			continue;
		}
		list_cmds = Func_list_cmds(cmds, list_cmds);
		free(cmds);
		if (list_cmds == NULL || list_cmds[0] == NULL)
		{
			free(cmds);
			break;
		}
		_status = execute(list_cmds);
		_free(list_cmds);
	}
	return (0);
}

char **Func_list_cmds(char *cmds, char **list_cmds)
{
	char *token;
	int i;

	i = 0;
	list_cmds = malloc(sizeof(char *) * 2);
	if (list_cmds == NULL)
	{
		perror("Error malloc ");
		return (NULL);
	}
	token = strtok(cmds, " \n");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		list_cmds[i] = strdup(token);
		if (list_cmds[i] == NULL)
		{
			perror("Error strdup ");
			return (NULL);
		}
		i++;
		list_cmds = realloc(list_cmds, ((i + 1) * sizeof(char *)));
		if (list_cmds == NULL)
		{
			perror("Error realloc");
			return (NULL);
		}
		token = strtok(NULL, " \n");
	}
	list_cmds[i] = NULL;
	return (list_cmds);
}


int execute(char **list_cmds)
{
	pid_t pid;
	int status;

	if (!strcmp(list_cmds[0], "exit"))
	{
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error ");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(list_cmds[0], list_cmds, environ) == -1)
		{
			perror("Error ");
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
char *read_cmd(char *cmds)
{
	size_t len;
	char *tmp;

	len = 0;
	getline(&cmds, &len, stdin);
	if (strlen(cmds))
	{
		if (strcmp(cmds, "exit"))
		{
			if (strncmp(cmds, "/bin/", 5) != 0)
			{
				tmp = malloc((strlen(cmds) + 6) * sizeof(char));
				if (tmp == NULL)
				{
					perror("Error malloc");
					return (NULL);
				}
				strcpy(tmp, "/bin/");
				strcat(tmp, cmds);
				cmds = tmp;
			}
		}
	}
	return (cmds);
}
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





