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
#include <signal.h>
extern char **environ;
int myexec(char *exec_path, char *args[], char *env_args[]);
char *str_concat(char *s1, char *s2);
char *get_value_env(char **envp, char *variable);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_realloc_pointer(void *ptr, unsigned int old_size, unsigned int new_size);
char **build_argv(char *lineptr);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *ptr, const char *delim);
int _strspn(const char *p, const char *s, int opt);
void sighandler(int);
int build_path(char **full_path, char *argv_0, char *envp[]);
#endif
