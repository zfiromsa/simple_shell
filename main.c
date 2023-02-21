#include "shell.h"


int main()
{
	char *cmd;

	cmd = NULL;
	while(1)
	{
		_readline(cmd);
	}
	free(cmd);
	return(0);
}

