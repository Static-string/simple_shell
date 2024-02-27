#include "shell.h"

/**
 * free_array - frees an array
 * @args: a pointer array
 */
void free_array(char **args)
{
	int v;

	if (args)
	{
		for (v = 0; args[v]; v++)
			free(args[v]);
		free(args);
	}
}

/**
 * Exit_Command - handle the exit builtin command
 * @cmd: the command input by the user
 * @cib: the command input buffer
 * @command_status: the command status
 * Return: exit status
 */
int Exit_Command(char **cmd, char *cib, int command_status)
{
	int exit_status;
	int m;

	if (cmd[1] == NULL)
	{
		free_array(cmd);
		free(cib);
		exit(command_status);
	}
	for (m = 0; cmd[1][m]; m++)
	{
		if (isdigit(cmd[1][m]) == 0)
		{
			free_array(cmd);
			return (1);
		}
	}
	exit_status = _atoi(cmd[1]);
	free_array(cmd);
	free(cib);
	exit(exit_status);
}
