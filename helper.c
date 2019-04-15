#include "holberton.h"
/**
  *sighandler - Function handle the signals
  *@signum: signal num
 */
void sighandler(int signum)
{
	char *prompt = "$jessiFer> ";
	(void)signum;
	int len;

	write(1,"\n",1);
	len = _strlen(prompt);
	write(1, prompt, len);
}
