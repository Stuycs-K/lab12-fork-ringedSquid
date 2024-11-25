#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define NUM_CHILDREN 2


int main() {
	pid_t children[NUM_CHILDREN];
	//Make an array of child pids
	//In the child pid, the current pid will be zero
	for (int i=0; i<NUM_CHILDREN; i++) {
		if (children[i] == 0) {
			break;
		}
		if (children[i] != 0) {
			children[i] = fork();
		}
	}
	printf("Hello from process");
	return 0;
}
