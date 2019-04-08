#include "holberton.h"

char *get_value_env(char **envp, char *value);
char *str_concat(char *s1, char *s2);
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **envp)
{
	char *token = NULL, *s = ":", *path, *full_path;
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);

		if (av[i][0] == '/' )
		{
			if (stat(av[i], &st) == 0)
			{
				printf(" FOUND\n");
			}
			else
			{
				printf(" NOT FOUND\n");
			}
		}
		else
		{
			token = strtok(get_value_env(envp, "PATH"), s);
			while( token != NULL )
			{
				path = str_concat(token, "/");
				if (path == NULL)
				{
					printf("ERRRORR en concat\n");
					return (-1);
				}
				full_path = str_concat(path,av[i]);
				free(path);
				if (full_path == NULL)
				{
					printf("ERRRORR en concat\n");
					return (-1);
				}
				if (stat(full_path, &st) == 0)
				{
					printf(" FOUND in %s\n", full_path);
					break;
				}
				free(full_path);
				token = strtok(NULL, s);
			}
			if(token == NULL)
			{
				printf(" NOT FOUND\n");
			}
		}
		i++;
	}
	return (0);
}
/**
 * get_value_env - find the value of enviroment variable
 * @envp: enviroment variables
 * @variable: variable to search
 * Return: pointer start on value of variable
 *
 */
char *get_value_env(char **envp, char *variable)
{
	unsigned int envp_i = 0, variable_i = 0;
	char flag;
	while (envp[envp_i])
	{
		flag= 1;
		while (variable[variable_i] && flag)
		{
			if (envp[envp_i][variable_i] != variable[variable_i])
				flag = 0;
			variable_i++;
		}
		if(flag)
		{
			envp[envp_i] = &envp[envp_i][variable_i + 1];
			return (envp[envp_i]);
		}
		variable_i = 0;
		envp_i++;
	}
	return (NULL);
}

/**
 * str_concat - Duplicate string
 * @s1: string one
 * @s2: string two
 * Return: pointer to copy array
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int i;
	unsigned int size_s1, size_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size_s1 = 0; *(s1 + size_s1) && s1; size_s1++)
	{
	}
	for (size_s2 = 0; *(s2 + size_s2) && s2; size_s2++)
	{
	}
	p =  malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size_s1 + size_s2; i++)
	{
		if (i < size_s1)
			p[i] = *(s1 + i);
		else
			p[i] = *(s2 + i - size_s1);
	}
	p[i] = '\0';
	return (p);
}
