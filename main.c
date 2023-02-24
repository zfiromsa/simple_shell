#include "shell.h"
/**
 * main - it simple shell
 * @argc: main parm
 * @argv: it main parm
 * @envp: it is environ
 * Return: succes 0, error 1, -1;
 */

int main(int argc, char *argv[], char **envp)
{
	char *command = NULL;
	size_t len = 0;
	char *stkn, **arr;
	pid_t my_pid;
	int i, status;

	while (argc >= 0)
	{
		printf("# ");
		getline(&command, &len, stdin);
		if (strcmp(command, "exit\n") == 0)
			return (0);
		stkn = strtok(command, " \n");
		arr = malloc(sizeof(char *) * 32);
		arr[0] = stkn;
		i = 1;
		while (stkn != NULL)
		{
			stkn = strtok(NULL, " \n");
			arr[i] = stkn;
			i++;
		}
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("ERROR");
			return (1);
		}
		else if (my_pid == 0)
		{
			execve(arr[0], arr, envp);
			printf("%s: no such file or directory\n", argv[0]);
		}
		else
			wait(&status);
	}
	free(command);
	return (0);
}

