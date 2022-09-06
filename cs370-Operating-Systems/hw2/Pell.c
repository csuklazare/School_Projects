// File name: Pell.c

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
	
	// double check to make sure argument was successfully passed
	if (argc < 1) {
		fprintf(stderr, "No file transferred.");
		exit(13);
	}

	// convert string into int
	int pellNum = atoi(argv[0]);

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
	return array[pellNum-1];
}
