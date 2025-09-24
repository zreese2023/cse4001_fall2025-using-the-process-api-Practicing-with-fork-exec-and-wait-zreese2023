#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		perror("error");
		exit(1);
	}
	if (pid == 0) {
		printf("child\n");
		exit(0);
	} else {
		int status;
		pid_t wpid = waitpid(pid, &status, 0);
		if (wpid == -1) {
			perror("wpid error");
		}
		if (WIFEXITED(status)) {
			printf("exit with code %d\n", WEXITSTATUS(status));
		}
	}
}
