#include "shell.h"

/**
 * _putchar - this function writes character to stdout
 * @c: character to be printed
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - this function prints character strings
 * @string: character pointer pointing to char
 * Return: character string
 */

void _print_string(const char *string)
{
	int v;

	for (v = 0; string[v] != '\0'; v++)
		_putchar(string[v]);
}

