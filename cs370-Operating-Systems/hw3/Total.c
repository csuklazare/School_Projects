#define BUFFER_SIZE 25
#define size 32
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <string.h>


int main(int argc, char *argv[]) {

	// check to make sure file is inputted
	if (argc < 2) {
		fprintf(stderr, "Not enough input provided.");
		exit(13);
	}	
	//convert string into int
	int total = atoi(argv[1]);
	
	// allowing access to the passed shared memory
	int fileDesc = shm_open(argv[0], O_RDWR, 0666);
	ftruncate(fileDesc, size);
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDesc, 0);

	// check to make sure the memory access is correct
	if (ptr == MAP_FAILED) {
		fprintf(stderr, "Total[%d]: Shared memory access failed!\n", getpid());
		exit(13);
	}

	// check to make sure number is in range
	if (total < 1 || total > 25) {

		fprintf(stderr, "Number is out of inclusive range. Please keep input in range 1-25 (inclusive on both ends).\n");
		exit(13);
	}

	// add all predecessor numbers to the total value, using a totalValue int variable
	int totalValue = 0;
	
	for (int i = 1; i <= total; i++) {
		totalValue = totalValue + i;
	}
	
	if (totalValue < 0) {
		
		fprintf(stderr, "Total[%d]: Integer overflow!!\n", getpid());
		exit(0);
	}
	printf("Total[%d] : Sum = %d\n", getpid(), totalValue);
	sprintf(ptr, "%d", totalValue);
	
	// unlinke memory
	if (shm_unlink(argv[0]) == -1) {
		printf("Error unlinking memory in the Total process!\n");
		exit(13);
	}

	return 0;
}
