#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 25
#define size 32

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	// double check to make sure file is inputted
	if (argc < 2) {
		fprintf(stderr, "No file name included. Please specify file name!\n");
		exit(1);
	}
	
	char* fileName = argv[1];
	int fd[2];
	pid_t pid;

	//create the pipe
	if (pipe(fd) == -1) {
		fprintf(stderr, "Pipe failed");
		exit(1);
	}
	// create variables to store return values from future pipes
	int pell;
	int composite;
	int total;
	int status;
	char string[BUFFER_SIZE];
	sprintf(string, "%d", fd[WRITE_END]);
	char runningTotal[BUFFER_SIZE];
	pid = fork();

		// error checking to make sure fork worked
		if (pid < 0) {

			fprintf(stderr, "Initiator[%d]: Fork Failed!\n", getppid());
			exit(1);
		}	

		// parent process if cid > 0
		if (pid > 0) {
			
			wait(&status);
			close(fd[WRITE_END]);
			read(fd[READ_END], &runningTotal, sizeof(runningTotal));
			close(fd[READ_END]);
			printf("Initiator[%d]:  contents read from the read end pipe: %d.\n", getppid(), runningTotal[0]);
			
		}

		// child process if cid > 0
		else{
			execlp("./Reader",fileName, string, NULL);
			
		}

		// create 3 shared memory segments
		const char *SHM_Pell = "SHM_Pell";
		const char *SHM_Composite = "SHM_Composite";
		const char *SHM_Total = "SHM_Total";

		int fdPell = shm_open(SHM_Pell, O_RDWR | O_CREAT, 0666);
		ftruncate(fdPell, size);
		void* ptrPell = mmap(0, size, PROT_READ, MAP_SHARED, fdPell, 0);

		int fdComposite = shm_open(SHM_Composite, O_RDWR | O_CREAT, 0666);
		ftruncate(fdComposite, size);
		void* ptrComposite = mmap(0, size, PROT_READ, MAP_SHARED, fdComposite, 0);

		int fdTotal = shm_open(SHM_Total, O_RDWR | O_CREAT, 0666);
		ftruncate(fdTotal, size);
		void* ptrTotal = mmap(0, size, PROT_READ, MAP_SHARED, fdTotal, 0);
		
		// check to make sure all of them were created successfully
		if (ptrPell == MAP_FAILED || ptrComposite == MAP_FAILED || ptrTotal == MAP_FAILED) {
			fprintf(stderr, "Initiator[%d]: shared memory creation failed!\n", getppid());
			printf("%d\n", errno);
			exit(1);
		}
		printf("Initiator[%d] : Created Shared memory \"SHM_Pell\" with FD: %d\n", getppid(), fdPell);
		printf("Initiator[%d] : Created Shared memory \"SHM_Composite\" with FD: %d\n", getppid(), fdComposite);
		printf("Initiator[%d] : Created Shared memory \"SHM_Total\" with FD: %d\n", getppid(), fdTotal);
		
		// Pell/Composite/total Processes
		pid_t pidPell;
		pid_t pidComposite;
		pid_t pidTotal;
		int statusPell;
		int statusComposite;
		int statusTotal;
		sprintf(string, "%d", runningTotal[0]);		// convert running total number into a string for use in execlp
		
		//Pell fork
		pidPell = fork();

		// error checking to make sure fork worked
		if (pidPell < 0) {
		
			fprintf(stderr, "Initiator[%d]: Pell Fork Failed!\n", getppid());
			exit(1);
		}

		// if pidPell ==0, then child process is entered
		if (pidPell == 0) {
			
			execlp("./Pell", SHM_Pell, string, NULL);
		}

		// Composite fork
		pidComposite = fork();

		// error checking to make sure fork worked
		if (pidComposite < 0) {
			
			fprintf(stderr, "Initiator[%d]: Composite Fork Failed!\n", getppid());
			exit(1);
		}

		// if pidComposite == 0, then child process is entered
		if (pidComposite == 0) {
		
			execlp("./Composite", SHM_Composite, string, NULL);
		}

		//total fork
		pidTotal = fork();

		// error checking to make sure fork worked
		if (pidTotal < 0) {
	
			fprintf(stderr, "Initiator[%d]: Total Fork Failed!\n", getppid());
			exit(1);
		}

		// if pidTotal = 0, then child process is entered
		if (pidTotal == 0) {

			execlp("./Total", SHM_Total, string, NULL);
		}

		// parent processes for pell/composite/total
		waitpid(pidPell, &statusPell, 0);
		pell = atoi(ptrPell);

		waitpid(pidComposite, &statusComposite, 0);
		composite = atoi(ptrComposite);

		waitpid(pidTotal, &statusTotal, 0);
		total = atoi(ptrTotal);
		
		printf("Initiator[%d] : Pell last number:   %d\n",getppid(), pell);
		printf("Initiator[%d] : Composite last number:   %d\n", getppid(), composite);
		printf("Initiator[%d] : Total last number:   %d\n", getppid(),  total);

	return 0;
}
