#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * string_token - this function tokenize a given string
 * @s: input string to be tokenized
 * @delim: character used to tokenize
 * Return: tokens
 */

char **string_token(char *s, char *delim)
{
	char *token;
	char *temp;
	char **ar;
	int len;

	temp = strdup(s);
	if (temp == NULL)
		return (NULL);
	token = strtok(temp, delim);
	len = 0;
	while (token != NULL)
	{
		++len;
		token = strtok(NULL, delim);
	}
	/* Locate memory for 'len' of words */
	ar = malloc(sizeof(char *) * (len + 1));
	if (ar == NULL)
	{
		free(temp);
		return (NULL);
	}
	/* Copy each tokens into ar */
	token = strtok(s, delim);
	len = 0;
	while (token != NULL)
	{
		ar[len] = strdup(token);
		if (ar[len] == NULL)
		{
			/* Free previous memory allocated if memory allocation fail */
			free_array(ar);
			return (NULL);
		}
		token = strtok(NULL, delim);
		++len;
	}
	free(temp);
	ar[len] = NULL;
	return (ar);
}

