#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int value = 23;
	printf("Before fork, value = %d\n", value);
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed");
		return 1;
	}
	else if (pid == 0) {
		printf("Child value = %d\n", value);
		value = 100;
		printf("Child changes value = %d\n", value);
	} 
	else {
		printf("Parent value = %d\n", value);
		value = 200;
		printf("Parent changes value = %d\n", value);
	}
	return 0;
}
