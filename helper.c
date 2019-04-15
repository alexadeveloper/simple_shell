#include "holberton.h"
/**
  *sighandler - Function handle the signals
  *@signum: signal num
 */
void sighandler(int signum)
{
	char *prompt = "$jessiFer> ";
	int len;
	(void)signum;

	write(1, "\n", 1);
	len = _strlen(prompt);
	write(1, prompt, len);
}
