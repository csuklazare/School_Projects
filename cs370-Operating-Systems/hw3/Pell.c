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
	
	// double check to make sure argument was successfully passed
	if (argc < 2) {
		fprintf( stderr, "Not enough input provided.");
		exit(13);
	}

	// allowing access to the passed shared memory
	int fileDesc = shm_open(argv[0], O_RDWR, 0666);
	ftruncate(fileDesc, size);
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDesc, 0);

	// check to make sure the memory access is correct
	if (ptr == MAP_FAILED) {
		fprintf(stderr, "Pell[%d]: Shared memory access failed!\n", getpid());
		exit(13);
	}

	// convert string into int
	int pellNum = atoi(argv[1]);

	// check to make sure number is in range
	if (pellNum < 1 || pellNum > 25) {

		fprintf(stderr, "Number is out of inclusive range. Please keep input in range 1-25 (inclusive on both ends).\n");
		exit(13);
	}
	
	printf("Pell[%d] : Number of terms in Pell series is %d\n", getpid(), pellNum);
	printf("Pell[%d] : The first %d numbers of the Pell sequence are:\n", getpid(), pellNum);
	// if pellNum < 2, enter different for loop then return.
	if (pellNum < 2) {
	
		for (int i = 0; i < pellNum; i++) {

			printf("%d,", i);
		}
		printf("\n");

		if (pellNum == 1) {
			return 0;
		}
		return 1;
	}
	
	// if pellNum >= 2, create array to store previous pell values then print first two values then lead into for loop
	int array[pellNum];
	array[0] = 0;
	array[1] = 1;
	printf("%d,%d,", array[0],array[1]);
	
	for (int i = 2; i < pellNum; i++) {
		array[i] = (2 * array[i-1]) + array[i-2];
		printf("%d,", array[i]);
		
	}
	
	//print new line before returning
	printf("\n");

	sprintf(ptr, "%d", array[pellNum-1]);
	
	// unlink memory
	if (shm_unlink(argv[0]) == -1) {
		printf("Error unlinking memory in the Pell Process!\n");
		exit(13);
	} 

	return 0;
}
