#include <stdio.h>
#include <signal.h> /* signal.hをインクルード */
#include <stdlib.h>
#include <string.h>

int	count;
/*
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};
*/
void	signal_handler(int signum)
{
	puts("中断します");
	exit(1);
}

int	main()
{
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);

	while (1)
	{
	}
	return 0;
}
