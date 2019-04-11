/**
  *sighandler - Function handle the signals
  *@signum: signal num
 */
void sighandler(int signum)
{
	printf("signal caputed: %d\n", signum);
}
