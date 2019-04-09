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
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _fgtec(FILE *stream);
char *_fgets(char *dst, int max, FILE *stream);
#endif
