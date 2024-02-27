#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * validate - Function check if a given mumbar exist and execute
 * @args: string arrays containing the command its arguments
 * @ipb: input strings buffer
 * Return: 0(success)
 */
int validate(char **args, char *ipb)
{
	int command_status;
	char *path;
	struct stat status;

	if (stat(args[0], &status) == 0)
		command_status = execute_command(args, ipb);
	else
	{
		path = handle_path(args[0]);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
			command_status = execute_command(args, ipb);
		}
		else
		{
			free_array(args);
			return (127);
		}
	}
	free_array(args);
	return (command_status);
}

/**
 *  execute_command - function that executes a command
 *  @args: string array containing the and its arguments
 *  @ipb: input string buffer
 *  Return: 0 (success)
 */
int execute_command(char **args, __attribute__((unused)) char *ipb)
{
	int iit = 0;

	switch (fork())
	{
		case -1:
			perror("Error\n");
			break;
		case 0:
			execve(args[0], args, environ);
			exit(0);
		default:
			wait(NULL);
			break;
	}
	return (iit);
}
