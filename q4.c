#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid < 0) {
		perror("error");
	}
	if (pid == 0) {
		execl("/bin/ls", "ls", "-1", (char *)NULL);
		perror("failed");
		exit(1);
	} else {
		wait(NULL);
	}
	return 0;
}
