#include <stdio.h>
#include <unistd.h>

/**
 * program that prints the parent process id
 */

int main(void)
{
	pid_t ppid;

	ppid = getppid();

	printf("%d\n", ppid);

	return (0);
}
