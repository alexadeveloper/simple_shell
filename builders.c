#include "holberton.h"
/**
 *build_argv - Build argv to send myexec
 *@lineptr: Line with value stored the information
 *Return: Array to pointers with Arguments
*/
char **build_argv(char *lineptr)
{
	/* hacer free cuando no se pueda hacer realloc hacer free */
	char **argv = NULL;
	char len = 1;

	lineptr = strtok(lineptr, " \n");
	while (lineptr != NULL)
	{
		argv = _realloc_pointer(argv, len - 1, len);
		argv[len - 1] = lineptr;
		lineptr = strtok(NULL, " \n");
		len++;
	}
	argv = _realloc_pointer(argv, len - 1, len);
	argv[len - 1] = NULL;
	return (argv);
}
/**
 *build_path - fin path to execute
 *@full_path: comand to execute
 *@argv_0: the arguments
 *@envp: the enviroment
 *Return: Pointer with the value of full path
*/
int build_path(char **full_path, char *argv_0, char *envp[])
{
	char *token = NULL, *s = ":", *path = NULL, *aux;
	struct stat st;

	if (argv_0[0] == '/')
	{
		if (stat(argv_0, &st) == 0)
		{
			*full_path = argv_0;
			return (0);
		}
		else
			return (-1);
	}
	else
	{
		aux = str_concat(get_value_env(envp, "PATH"), "");
		token = strtok(aux, s);
		while (token != NULL)
		{
			path = str_concat(token, "/");
			if (path == NULL)
			{ free(aux);
				printf("ERRRORR en concat\n");
				return (-1); }
			*full_path = str_concat(path, argv_0);
			free(path);
			if (*full_path == NULL)
			{ free(aux);
				printf("ERRRORR en concat\n");
				return (-1); }
			if (stat(*full_path, &st) == 0)
			{ free(aux);
				return (1); }
			free(*full_path);
			token = strtok(NULL, s);
		}
		free(aux);
		return (-1);
	}
}