// Responsible for implementing the following:
// 1. Dynamically allocate and de-allocate a random sized array for each iteration.
// 2. Populate elements in the array with random integers.
// 3. For each iteration, generate a random integer to be used as a divisor.
// 4. For each element in the array, check if the element is divisible, and if so count it.
// 5. Calculate the ratio of elements divisible by divisor to elements not divisible by the divisor.
// ---- Number of Divisible Elements /Number of Non-Divisble Elements ----
// 6. At the end print the iteration number with maximum number of divisible elements.
// 7. Return the average value of the ratio divisible/not_divisible for all iterations to Initiator

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// return a random integer value between a lower bound (inclusive) and an upper bound (exclusive)
int random_in_range(int lower_bound, int upper_bound) {

	return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}

// return the number of divisible elements in an array by the divisor i.e. array[i] % randomDividend = 0
int get_divisibility_count(int* array, int arraySize, int randomDividend) {

	int divisibleElements = 0;
//	printf("%d is the divisor\n", randomDividend);
	for (int i = 0; i < arraySize; i++) {		// iterate through each element
//		printf("%d is the value of the array at position %d\n", array[i], i);
		if (array[i] % randomDividend == 0) {		// is the element evenly divisible by the divisor?

			divisibleElements = divisibleElements + 1;		// if so, incrememnt total by 1
//			printf("%d is the divisible elements\n", divisibleElements);
		}
	}
	return divisibleElements;
}

// return a random size for the array
int size_of_array() {

	return random_in_range(100, 150);
}

// populate the given array with random values
int* populate_array(int* array, int sizeOfArray) {

//	printf("%d is size\n", size);
	for (int i=0; i < sizeOfArray; i++) {
		array[i] = random_in_range(1,100);
//		printf("%d is array at position %d\n", array[i], i);
	}
	return array;
}

//calculate the ratio to add onto the returnRatio
float divisible_ratio(float divisibleElements, float sizeOfArray) {
	
	float returnValue = 1;		// if every element is divisible, return 1 (or 100%)
	if (sizeOfArray-divisibleElements > 0) {
//		printf("I ENTERED THE IF STATEMENT");
		returnValue = divisibleElements/(sizeOfArray-divisibleElements);		// calculate the % for return ratio
	}
//	printf("return value being returned is %f\n", returnValue);
	return returnValue;
}

//return the running ratio of divisible elements to non-divisible elements over a random number of arrays
float get_running_ratio() {

	int maxDivisibleElements = 0;		// # of elements divisible by divisor
	int maxCountIteration = 0;		// iteration num. array belongs to
	int totalIterations = random_in_range(50, 100);		// how many arrays will be allocated/deallocated
	float returnRatio = 0.0;		// keep track of running sum of the ratio

	printf("[Worker]: Number of iterations is: %d\n", totalIterations);

	for (int i = 0; i < totalIterations; i++) {	// create arrays of random size, fill with random numbers, check if each element is divisble by random divisor, keep track of max divisible elements
		int sizeOfArray = size_of_array();
	//	printf("%d is the size of the array before initialization\n", sizeOfArray);
		int* array = (int*)calloc(sizeOfArray, sizeof(int));
	//	printf("%d is the size of the array\n", sizeof(array));i
		populate_array(array, sizeOfArray);		 // populate the array with numbers
	//	printf("%d time through loop, %d size of array\n", i, sizeOfArray);
		int divisor = random_in_range(5,15);		 // create a random divisor
		int divisibleElements =	get_divisibility_count(array, sizeOfArray, divisor);		 // return number of divisible elements in the array
	//	printf("%d divisible elements \n", divisibleElements);
		returnRatio = returnRatio + divisible_ratio(divisibleElements, sizeOfArray);			 // update running sum of the returnRatio
	//	printf("%.6f = returnRatio\n", returnRatio);
		if (divisibleElements > maxDivisibleElements) {		 // check to see if there are more divisible elements in this array. If there are, update variables accordingly

			maxDivisibleElements = divisibleElements;
			maxCountIteration = i;
		}
// COMMENT OUT THE BELOW LINE TO CREATE A MEMORY LEAK
		free(array);		// free memory for next array usage
	}
	maxCountIteration = maxCountIteration + 1;		// add 1 to correctly account for the 0th element.	
	printf("[Worker]: Iteration with maximum fully divisible elements is %d\n", maxCountIteration);

	return returnRatio/totalIterations;
}
