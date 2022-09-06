// File name: Total.c

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

	// check to make sure file is inputted
	if (argc < 1) {
		fprintf(stderr, "No file included.");
		exit(13);
	}	
	//convert string into int
	int total = atoi(argv[0]);

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

	return totalValue;
}
