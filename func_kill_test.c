#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int	main()
{
	int         p_id;
//forkは子プロセスなら0,親プロセスならそれ以外
	if ((p_id = fork()) == 0)
	{
		printf("p_id,child%d\n",p_id);
    		/* 子プロセス */
    		while (1) 
		{
			printf("子プロセス実行中\n");
      			sleep(1);
		}
	}
	else
	{
		printf("p_id,parent%d\n",p_id);
		/* 親プロセス */
		sleep(4);
		/* 子プロセスに終了シグナルを送信 */
		kill(p_id,  SIGINT);
		wait(NULL);
		printf("親プロセス終了\n");
	}
	return 0;
}
