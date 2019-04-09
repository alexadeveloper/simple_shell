#include "holberton.h"
/*int _fgetc(FILE *stream)
{
	char car;
	ssize_t aux;

	aux = read(stream->fd, &car, 1);
return(aux);
}
char *_fgets(char *dst, int max, FILE *stream)
{
	int c;
	char *ptr;
	char car;

	max--;
	(void) stream;
	for (ptr = dst; max > 0; max --)
	{
		c = read(0, &car, 1);
		*ptr++ = c;
		if (c == '\n')
			break;
	}
return(ptr);
}
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
  static char line[256];
  char *ptr;
  unsigned int len;

  if (lineptr == NULL || n == NULL)
    {
      return -1;
    }

  if (ferror (stream))
    return -1;

  if (feof(stream))
    return -1;
     
  fgets(line,256,stream);

  len = strlen(line);
   
  if ((len+1) < 256)
    {
      ptr = realloc(*lineptr, 256);
      if (ptr == NULL)
	return(-1);
      *lineptr = ptr;
      *n = 256;
    }

  strcpy(*lineptr,line); 
  return(len);
}
