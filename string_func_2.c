#include "shell.h"

/**
 * _strncat - this function concatenates two strings
 * @dest: string destination
 * @src: string source
 * @n: number of nytes to append
 * Return: pointer to destination
 */

char *_strncat(char *dest, char *src, int n)
{
	int x, y;

	x = 0;
	while (dest[x] != '\0')
	{
		x++;
	}
	for (y = 0; src[y] != '\0' && n > 0; y++, y--, x++)
	{
		dest[x] = src[y];
	}
	return (dest);
}

/**
 * _strncpy - this function copies n bytes of a string
 * @dest: string destination
 * @src: string source
 * @n: number of bytes to be copied
 * Return: zero
 */

char *_strncpy(char *dest, char *src, int n)
{
	int t;

	for (t = 0; t < n && src[t] != '\0'; t++)
		dest[t] = src[t];

	for (; n > t; t++)
		dest[t] = '\0';

	return (dest);
}

/**
 * _strcpy - this function copies the string pointed
 * to by src
 * @dest: string destination
 * @src: string source
 * Return: zero
 */

char *_strcpy(char *dest, char *src)
{
	int len;
	int g;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	for (g = 0; g < len; g++)
	{
		dest[g] = src[g];
	}
	dest[g] = '\0';
	return (dest);
}

/**
 * _strcat - this function concatenates two strings
 * @dest: string destination
 * @src: string source
 * Return: zero
 */

char *_strcat(char *dest, char *src)
{
	int k = 0;
	int o;

	while (dest[k] != '\0')
		k++;
	for (o = 0; src[o] != '\0'; o++)
	{
		dest[k] = src[o];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

