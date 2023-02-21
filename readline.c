#include "shell.h"

void _readline(char* cmd)
{
	size_t size_cmd;

	size_cmd = 10;
	printf("$");
	readline(&cmd, &size_cmd, stdin);
}
