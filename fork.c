#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pid = fork();
	if (pid == 0)
		printf("Hello from Child!, my PID is %u, and my parentID is %u\n", getpid(), getppid());
  	else
		printf("Hello from Parent!, my PID is %u, and my parentID is %u, and my child is %u\n", getpid(), getppid(), pid);
	return (0);
}
