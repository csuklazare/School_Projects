#include <iostream>

using namespace std;

	
int main(int , char* argv[]) {
	
	string nameOfFile = argv[0];

//	if (argc < 2) {
//
//		cerr << nameOfFile << ": no input given. Please type in at least 1 integer between 0 and 99.\n";
//		exit(0);
//	}

	int input;
	int array[100];
	
	// initialize the array to all 0's
	for (int i = 0; i < 100; i++) {

		array[i] = 0;
	}

	// begin sort counting and storing the # of times a number is seen into the array
	while (cin >> input) {
		
		if(input<0 || input > 99) {

			cerr << nameOfFile << ": Invalid input. Integer has to be between 0 and 99.\n";
			exit(0);
		}
		array[input] = array[input] + 1;
	}
	int lastElement = 99;
	// find largest element that has size > 1
	for (int i = 99; i > 0; i--) {
		
		if (array[i] > 0) {
			lastElement = i;
			break;
		}

	}
	// print out frequency of each number 1st format (1x2 10x5 etc.)
	for (int i = 0; i < lastElement + 1; i++) {
		
		if (array[i] != 0) {

			if (i != lastElement) {
				cout << i << "x" << array[i] << " ";
			}
			else {
				cout << i << "x" << array[i];
			}
		}
	}
	cout << "\n";
	// print out frequency of each number 2nd format (1,1,2,2,etc.)
	for (int i = 0; i < lastElement + 1; i++) {

		if (array[i] != 0) {
		
			if (i != lastElement) {		// if isn't equal to last element, print i array[i] times with , in between
				for (int j = 0; j < array[i]; j++) {
				
					cout << i << ",";
				}
			}
			else {				// if i equals last element, print i + "," array[i]-1 times, then print one last i w/o comma
				int counter = array[i];
				while (counter != 1) {
					
					cout << i << ",";
					counter = counter - 1;
				}
				cout << i;
			}
		}
	}
	cout << "\n";
	return 0;
}
