#include "holberton.h"
extern char **environ;
int main(int ac, char *argv[], char *envp[])
{
	printf("Direccion of envp: %p\n adress environ %p\n", envp, environ);
	return (0);
}
