#include "shell.h"

/**
 * _strncmp - this function compares two strings
 * @s1: first string input to be compared
 * @s2: second string input to be compared
 * @n: number of characters to be compared
 * Return: 0 if strings are equal to n, else 1.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t v;

	for (v = 0; (s1[v] != '\0' || s2[v] != '\0') && v < n; v++)
	{
		if (s1[v] != s2[v])
			return (s1[v] - s2[v]);
	}
	return (0);
}

/**
 * _strcmp - this function compares two strings
 * @s1: first string input
 * @s2: second string input
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int w;

	for (w = 0; s1[w] != '\0' || s2[w] != '\0'; w++)
	{
		if (s1[w] != s2[w])
			return (s1[w] - s2[w]);
	}
	return (0);
}

/**
 * _strlen - this function returns the lenght of a string
 * @s: string variable
 * Return: 0
 */

int _strlen(char *s)
{
	int q;

	for (q = 0; s[q] != '\0'; q++)
		;

	return (q);
}

/**
 * _string_dup - this function duplicates a string
 * @string: the string tio duplicate
 * Return: pointer to the string duplicated
 */

char *_string_dup(const char *string)
{
	int len = 0;
	char *ren;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	ren = malloc(sizeof(char) * (len + 1));
	if (!ren)
		return (NULL);
	for (len++; len--;)
		ren[len] = *--string;
	return (ren);
}

