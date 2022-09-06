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

	//check to make sure file is inputted
	if (argc < 2) {
		fprintf(stderr, "Not enough input provided.");
		exit(13);
	}
	int compositeNum = atoi(argv[1]);
	
	// allowing access to the passed shared memory
	int fileDesc = shm_open(argv[0], O_RDWR, 0666);
	ftruncate(fileDesc, size);
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDesc, 0);
	
	// check to make sure memory access is correct
	if (ptr == MAP_FAILED) {
		fprintf(stderr, "Composite[%d]: Shared memory access failed!\n", getpid());
		exit(13);
	}

	// check to make sure number is in range
	if (compositeNum < 1 || compositeNum > 25) {

		fprintf(stderr, "Number is out of inclusive range. Please keep input in range 1-25 (inclusive on both ends).\n");
		exit(13);
	}
	printf("Composite[%d]: First %d composite numbers are:\n",getpid(),compositeNum);

	int array[compositeNum];
	int x = 0;
	int dividend = 4; 	// set dividend equal to first composite number

	//find the composite numbers and add them to the array
	while (x != compositeNum) {
		
		for (int i = 2; i < dividend; i++) {

			if (dividend % i == 0) {
				array[x] = dividend;
				x++;
				break;
			}
		}
		dividend++;
	}

	//print out composite numbers
	for (int i = 0; i < compositeNum; i++) {

		printf("%d,", array[i]);
	}

	//print new line
	printf("\n");
	sprintf(ptr, "%d", array[compositeNum-1]);
	
	// unlink memory
	if (shm_unlink(argv[0]) == -1) {
		printf("Error unlinking memory in the Composite Process!\n");
		exit(13);
	}

	return 0;	


}
