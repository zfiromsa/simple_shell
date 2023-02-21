#include "shell.h"


int main(void)
{
	char *cmd = NULL;
	size_t len;

        len = 0;
	while(1)
	{
		printf("$$");
	        getline(&cmd, &len, stdin);
		printf("%s\n", cmd);
	}
	free(cmd);
	return(0);
}

