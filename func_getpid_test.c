#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int pid_a;
	int pid_b;

	pid_a = getpid();
	pid_b = getppid();
	printf("Current Process PID:%d\n",pid_a);
	printf("Parent Process PID:%d\n",pid_b);
	return 0;
}
