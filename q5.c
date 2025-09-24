#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid = fork();
	
	if (pid < 0) {
		perror("error");
		exit(1);
	}
	if (pid == 0) {
		printf("child\n");
	} else {
		wait(NULL);
		printf("parent\n");
	}
	return 0;
}
