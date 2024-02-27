#include "shell.h"

/**
 *  main - program stats
 *  Return: program
 */
int main(void)
{
	char *prompt;
	char *line = NULL;
	char **token_array;
	int int_mode_ = isatty(STDIN_FILENO);
	int exit_Status = 0;
	size_t size = 0;
	ssize_t n_chars_read;

	while (1)
	{
		prompt = "VAC-SHELL:~$ ";
		if (int_mode_ == 1)
			_print_string(prompt);
		n_chars_read = getline(&line, &size, stdin);
		if (n_chars_read == -1)
		{
			if (int_mode_ == 1)
				_putchar('\n');
			break;
		}
		if (line[n_chars_read - 1] == '\n')
			line[n_chars_read - 1] = '\0';

		token_array = string_token(line, " \t");
		if (token_array[0] == NULL)
		{
			free(token_array);
			continue;
		}
		exit_Status = builtin(token_array, line, exit_Status);
		if (exit_Status == 1)
			exit_Status = validate(token_array, line);
	}
	free(line);
	return (exit_Status);
}

