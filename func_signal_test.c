#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//シグナルハンドラとしたい関数
void	signal_handler(int signum)
{
	puts("中断します");
	exit(1);
}

int	main()
{
	signal(SIGINT,signal_handler);
	while(1)
	{
	}
	return (0);
}
