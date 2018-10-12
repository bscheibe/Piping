#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void main() {
	int i = 1;
	while (i < 11) {
		printf("Child has been asleep for %d seconds.\n", i++);
		sleep(1);
	}
}
