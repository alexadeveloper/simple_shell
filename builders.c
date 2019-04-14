#include "holberton.h"
/**
 *build_argv - Build argv to send myexec
 *@lineptr: Line with value stored the information
 *Return: Array to pointers with Arguments
*/
char **build_argv(char *lineptr)
{
	char **argv = NULL;
	char len = 1;

	lineptr = strtok(lineptr, " \t\n");
	while (lineptr != NULL)
	{
		argv = realloc_pointer(argv, len - 1, len);
		argv[len - 1] = lineptr;
		lineptr = strtok(NULL, " \t\n");
		len++;
	}
	argv = realloc_pointer(argv, len - 1, len);
	if (argv == NULL)
		return (NULL);
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
int build_path(int c, char **full_path, char *argv_0, char *envp[])
{
	char *token = NULL, *s = ":", *path = NULL, *aux;
	struct stat st;

	if (argv_0[0] == '/')
	{
		if (stat(argv_0, &st) == 0)
		{
			*full_path = str_concat("", argv_0);
			return (0);
		}
		else
		{
			*full_path = str_concat("", "");
			not_found_command(c, argv_0);
			return (-1);
		}
	}
	else
	{
		aux = str_concat(get_value_env(envp, "PATH"), "");
		token = strtok(aux, s);
		while (token != NULL)
		{
			path = str_concat(token, "/");
			if (path == NULL)
			{
				free(aux);
				printf("ERRRORR en concat\n");
				return (-1);
			}
			*full_path = str_concat(path, argv_0);
			free(path);
			if (*full_path == NULL)
			{
				free(aux);
				printf("ERRRORR en concat\n");
				return (-1);
			}
			if (stat(*full_path, &st) == 0)
			{
				free(aux);
				return (1);
			}
			free(*full_path);
			token = strtok(NULL, s);
		}
		free(aux);
		*full_path = str_concat("", "");
		not_found_command(c, argv_0);
		return (-1);
	}
}
/**
 * getfunction- selects the correct function to perform the operation
 * @builtin: Operator given
 *
 * Return: a pointer to the function that corresponds to the operator given
 */
void (*getfunction(char *builtin))(char **argvs, char *line, int status)
{
	int i_struct = 0;
	op_t print[] = {
		{"exit", exit_handler},
		{NULL, NULL}
	};

	while (print[i_struct].op != NULL)
	{
		if (_str_cmp(builtin, print[i_struct].op))
		{
			return (print[i_struct].f);
		}
		i_struct++;
	}
	return (NULL);
}
/**
 * exit_handler
 * @argvs: arguments with exit
 */
void exit_handler(char **argvs, char *line, int status)
{
	if (argvs[1] == NULL)
	{
		free(argvs);
		free(line);
		exit(status);
	}
	else
	{
		status = _atoi(argvs[1]);
		free(argvs);
		free(line);
		exit(status);
	}
}
