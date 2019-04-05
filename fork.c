#include <unistd.h>
#include <stdio.h>
int main()
{
	if (fork() == 0)
		printf("Hello from Child!\n");
  	else
		printf("Hello from Parent!\n");
	return (0);
}
