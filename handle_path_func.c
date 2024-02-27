#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/**
 * handleEnv - prints the environ variables
 * @user_command: user command
 * Return: environment variables
 */
int handleEnv(char **user_command)
{
	char **env;

	env = environ;
	if (user_command[1] != NULL)
		return (1);
	while (*env != NULL)
	{
		_print_string(*env);
		_putchar('\n');
		env++;
	}
	return (0);
}

/**
 * handle_path - function that handles full path
 * @args: command array
 * Return: 0(success)
 */
char *handle_path(char *args)
{
	char path[BUFSIZ];
	char **path_arr;
	char *temp;
	int v;
	struct stat status;

	temp = getenv("PATH");
	_strcpy(path, temp);
	path_arr = string_token(path, ":");
	for (v = 0; path_arr[v]; v++)
	{
		temp = malloc(sizeof(char) * (_strlen(path_arr[v]) + _strlen(args) + 2));
		if (temp == NULL)
		{
			perror("Memory is not Allocated");
			break;
		}
		_strcpy(temp, path_arr[v]);
		_strcat(temp, "/");
		_strcat(temp, args);

		if (stat(temp, &status) == 0)
		{
			if (path_arr != NULL)
				free_array(path_arr);
			return (temp);
		}
		if (temp != NULL)
			free(temp);
	}
	free_array(path_arr);
	return (NULL);
}

