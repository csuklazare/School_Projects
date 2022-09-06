// Responsible for:
// Setting the seed, whose value is passed as an argument, using srand()
// Invoking funcitons in the Worker
#include <stdio.h>
#include <stdlib.h>
#include "Worker.h"
// Main function

int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("Error, too few or too many arguments. Program expects 1 argument.");
		exit(0);
	}
	int seed = atoi(argv[1]);		// check to make sure input is valid integer
	srand(seed);		// update seed with integer

	printf("[Initiator]: With seed: %d\n", seed);

	float running_ratio = get_running_ratio();		// call funciton in Worker
	
	printf("[Initiator]: Running ratio: %f\n", running_ratio);

	return 0;
}
