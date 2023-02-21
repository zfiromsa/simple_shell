#include "shell.h"

void readline(char* cmd)
{
	unsigned int len;

	len = 0;
	getline(&cmd, &len, stdin);
}
