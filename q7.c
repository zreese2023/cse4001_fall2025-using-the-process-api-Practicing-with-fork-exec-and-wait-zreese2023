#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Error");
		exit(1);
	}
	if (pid == 0) {
		printf("Child process before closing stdout\n");
		close(STDOUT_FILENO);
		printf("Child after closing stdout\n");
		exit(0);
	} else {
		printf("Parent waiting for child\n");
		sleep(1);
	}
	return 0;
}
