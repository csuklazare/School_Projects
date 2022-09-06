#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

	if (argc < 2) {
		fprintf(stderr, "Error: not enough arguments passed to reader!\n");
		exit(1);
	}

	FILE *file = fopen(argv[0], "r");		// file to be read
	int pipeRef = atoi(argv[1]);			// pipe reference
	int number = 0;					// current number being read
	int total = 0;					// running total
	fscanf(file, "%d", &number);			// scan first number
	while (!feof(file)) {				// while the end of the file has not been reached, add the number onto the running total, and scan for the next number
		total = total + number;
		fscanf(file, "%d", &number);
	}
	fclose(file);					// close the file

	close(pipeRef-1);				// close the reader, which is the write reference -1

	write(pipeRef, &total, sizeof(total));		// write the output to the pipe
	close(pipeRef);					// close the writer
	return 0;

}
