#include "holberton.h"

int main(void)
{
	pid_t pid;
	int times = 0, wstatus = 0;
	char *args[] = {"ls","-l","/tmp",NULL};
	char *env_args[] = {"PATH=/bin",NULL};

	while (times < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			write(STDOUT_FILENO,"Error process\n",14);
			return (-1);
		}
		else if(pid == 0)
		{
//			write(STDOUT_FILENO,"Soy el hijo\n",12);
			if (execve("/bin/ls", args, env_args) == -1)
			{
				write(STDOUT_FILENO,"Error execv\n",12);
				return (-1);
			}
		}
		else{
			waitpid(pid, &wstatus, 0);
		}
		times++;
	}
	return (0);
}
