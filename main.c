#include "shell.h"

int main(int argc, char *argv[])
{
        char *command = NULL;
        size_t len = 0;
        char *stkn;
        pid_t my_pid;
        int status, i;

        while (argc >= 0)
        {
                char **arr;

                printf("($)");
                getline(&command, &len, stdin);
                stkn = strtok(command, " \n");

                arr = malloc(sizeof(char *) * 32);
                arr[0] =stkn;

                i = 1;
                while (stkn != NULL)
                {
                        stkn = strtok(NULL, " \n");
                        arr[i] = stkn;
                        i++;
                }

                my_pid = fork();
                if (my_pid== -1)
                {
                        perror("ERROR");
                        return (1);
                }
                else if(my_pid == 0)
                {
                        execve(arr[0], arr, NULL);
			printf("%s: no such file or directory\n", argv[0]);
                }
                else
                        wait(&status);
        }
        free(command);
        return (0);
}

