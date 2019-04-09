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
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);
#endif
