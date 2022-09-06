// file name: Initiator.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	// double check to make sure file is inputted
	if (argc < 1) {
		fprintf(stderr, "No file name included. Please specify file name!");
		exit(1);
	}
	// obtain input from a file and iterate through until no more lines in file
	FILE *fp;
	fp = fopen(argv[1], "r");
	char buf[256];
	
	while (fgets(buf,sizeof(buf), fp)) {
	
		pid_t cid;
		int pell = 0;
		int composite = 0;
		int total = 0;
		int status;

		// PELL PROCESS if/elif/else statements
		cid = fork();
	

		// error checking to make sure fork worked
		if (cid < 0) {

			fprintf(stderr, "Initiator[%d]: Fork Failed!\n", getppid());
			exit(1);
		}	

		// child process if cid=0
		else if (cid == 0) {

			printf("Initiator[%d]: Forked process with ID %d.\n", getppid(), getpid());
			printf("Initiator[%d]: Waiting for Process [%d].\n", getppid(), getpid());
			execlp("./Pell",buf, NULL);
			
		}

		// parent process if cid > 0
		else{
			
			wait(&status);
			if (WIFEXITED(status)) {
				
				pell = WEXITSTATUS(status);
				if (pell == 13) {
				
					fprintf(stderr, "Error: number in text file out of range or invalid. Please type in number in the range 1-25 (inclusive) only.\n");
					exit(1);
				}
				printf("Initiator: Child process %d returned %d.\n", cid, pell);	
			}
		}


		// COMPOSITE PROCESS if/elif/else statements
		cid = fork();
		
		// error checking to make sure fork worked
		if (cid < 0) {

			fprintf(stderr, "Initiator[%d]: Fork Failed!\n", getppid());
			exit(1);
		}

		// child process if cid=0
		else if (cid == 0) {
	
			printf("Initiator[%d]: Forked process with ID %d.\n", getppid(), getpid());
			printf("Initiator[%d]: Waiting for Process [%d].\n", getppid(), getpid());
			execlp("./Composite", buf, NULL);
		}

		// parent process if cid >0
		else {

			
			wait(&status);
			if (WIFEXITED(status)) {

				composite = WEXITSTATUS(status);
				printf("Initiator: Child process %d returned %d.\n", cid, composite);
			}
		}


		// TOTAL PROCESS if/elif/else statements
		cid = fork();
		
		// error checking to make sure fork worked
		if (cid < 0) {

			fprintf(stderr, "Initiator[%d]: Fork Failed!\n", getppid());
			exit(1);
		}

		// child process if cid=0
		else if (cid == 0) {
	
			printf("Initiator[%d]: Forked process with ID %d.\n", getppid(), getpid());
			printf("Initiator[%d]: Waiting for Process [%d].\n", getppid(), getpid());
			execlp("./Total", buf, NULL);
		}

		// parent process if cid >0
		else {

			wait(&status);
			if (WIFEXITED(status)) {

				total = WEXITSTATUS(status);
				printf("Initiator: Child process %d returned %d.\n", cid, total);
			}
		}
	
		printf("Initiator: Pell: %d\n", pell);
		printf("Initiator: Composite: %d\n", composite);
		printf("Initiator: total Count: %d\n", total);
	}

	// close the file
	fclose(fp);
	
	return 0;
}
