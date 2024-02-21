#include <stdio.h>
#include <stdlib.h>

/**
 * a program that prints arguments
 */

int main(int ac, char **av)
{
	int i;
	int sum = 0;

	for (i = 0; i < ac; i++)
	{
		int num = atoi(av[i]);
		if (num > 0 || av[i][0] == '0')
		{
			sum += num;
		}
		else
		{
			printf("Invalid argument: %s\n", av[i]);
		}
		printf("argv[%d]: %s\n",  i, av[i]);
	}
	printf("argv sum is: %d\n", sum);

	return (0);
}
