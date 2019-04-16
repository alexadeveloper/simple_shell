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
/**
 * print_number_error - print number in standar output
 * @number: number to print
 */
void print_number_error(int number)
{
	if (number > 9)
	{
		print_number_error(number / 10);
		print_number_error(number % 10);
	}
	else
	{
		char n = number + '0';

		write(STDERR_FILENO, &n, 1);
	}
}
