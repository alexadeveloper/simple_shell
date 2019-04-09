#include "holberton.h"

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
