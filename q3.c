#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {

	pid_t pid = fork();
	if (pid < 0) {
		perror("error");
		exit(0);
	}
	if (pid == 0) {
		printf("hello\n");
	} else {
		sleep(1);
		printf("goodbye\n");
	}
	return 0;
}
