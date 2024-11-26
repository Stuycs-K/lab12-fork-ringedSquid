#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main() {
	pid_t c1, c2, cf;
	int time_s;
	printf("%d about to fork 2 processes\n", getpid());
	c1 = fork();
	//Check if this is the parent process
	if (c1 != 0) {
		c2 = fork();
	}
	//If a child process
	if (c1 == 0 || c2 == 0) {
		srand(getpid());
		time_s = (rand() % 5) + 1;
		printf("%d %d sec\n", getpid(), time_s);
		sleep(time_s);
		printf("%d finished after %d seconds\n", getpid(), time_s);
		exit(time_s);
	}
	int status;
	cf = wait(&status);
	printf("main process %d finished. child %d slept for %d seconds.\n", getpid(), cf, WEXITSTATUS(status));
	return 0;
}
