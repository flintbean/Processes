// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?
//Answer: It looks like they work fine together

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;

	fp = fopen("text.txt", "w+");
	

	pid_t pid = fork();

	if (pid == 0) {
		printf("I'm the child process, and my pid is %d!\n", getpid());
		fprintf(fp, "We are in Child, pid:%d\n", getpid());
	}
	else {
		printf("I'm the parent process, and my pid is %d!\n", getpid());
		fprintf(fp, "We are in Parent, pid:%d\n", getpid());
	}

	fclose(fp);
    
    return 0;
}
