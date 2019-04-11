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
