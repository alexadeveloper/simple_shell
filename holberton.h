#ifndef __HOLBERTON__
#define __HOLBERTON__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
int myexec(char *exec_path, char *args[],char *env_args[]);
char *str_concat(char *s1, char *s2);
char *get_value_env(char **envp, char *variable);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
