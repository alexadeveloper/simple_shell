#include "holberton.h"
/**
 * @ac: arguments counter
 * @argv: argument values
 * @envp: enviroment variables
 * Return: Succes always
 */
int main(int ac, char *argv[], char *envp[])
{
	printf("Direccion of envp: %p\n adress environ %p\n", envp, environ);
	return (0);
}
