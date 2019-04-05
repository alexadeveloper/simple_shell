#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
  *main - pnritn the PID of the parent process
  *Return: always 0
 */
int main(void)
{
	pid_t mypid;
	pid_t myppid;

	mypid = getpid();
	myppid = getppid();
	printf("mypid: %u\n", mypid);
	printf("myppid: %u\n", myppid);
	return (0);
}
