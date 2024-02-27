#include "shell.h"

/**
 * _atoi - converts a string to integer
 * @k: string to be converted
 * Return: int converted from the string
 */
int _atoi(char *k)
{
	int v = 0,	m = 0,	t = 0;
	int len = 0, u = 0,	p = 0;

	while (k[len] != '\0')
		len++;

	while (v < len && u == 0)
	{
		if (k[v] == '-')
			++m;

		if (k[v] >= '0' && k[v] <= '9')
		{
			p = k[v] - '0';
			if (m % 2)
				p = -p;
			t = t * 10 + p;
			u = 1;
			if (k[v + 1] < '0' || k[v + 1] > '9')
				break;
			u = 0;
		}
		v++;
	}

	if (u == 0)
		return (0);
	return (t);
}

