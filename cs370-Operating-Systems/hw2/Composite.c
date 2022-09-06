// File Name: composite.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

	//check to make sure file is inputted
	if (argc < 1) {
		fprintf(stderr, "No file inputted.");
		exit(13);
	}
	int compositeNum = atoi(argv[0]);

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
	return array[compositeNum-1];	


}
