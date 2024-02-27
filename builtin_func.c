#include "shell.h"

/**
 * builtin - builtin handles
 * @args:  The command entered
 * @l: line
 * @prog_status: status of the program
 * Return: Return 0 if builtin is found, else 1
 */
int builtin(char **args, char *l, int prog_status)
{
	char *builtin_command[] = {"exit", "env", NULL};

	if (_strcmp(builtin_command[0], args[0]) == 0)
	{
		return (Exit_Command(args, l, prog_status));
	}
	else if (_strcmp(builtin_command[1], args[0]) == 0)
	{
		return (handleEnv(args));
	}
	else
		return (1);
}
