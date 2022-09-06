#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

// functions at the top to divide and conquer program

// print out numbers in first format
void firstFormat(int array[], long range, long firstValue) {

	int counter = 0;
	for (int i = 0; i < range; i++) {
		if (array[i] == 0) {
			continue;
		}
		
		if (counter == 0) {
			cout << i + firstValue << "x" << array[i];
			counter = counter + 1;
		}
		else {
			cout << " " << i + firstValue << "x" << array[i];	
		}
	}
	cout << "\n";
}

// print out numbers in second format
void secondFormat(int array[], long range, long firstValue) {

	int counter = 0;	
	for (int i = 0; i < range; i++) {
		if (array[i] == 0) {
			continue;
		}
		if (counter == 0) {
			for (int j = 0; j < array[i]-1; j++) {	
				cout << i + firstValue << ",";
			}
			cout << i + firstValue;
			counter = counter + 1;
		}
		else {
			for (int j = 0; j < array[i]; j++) {
				cout << "," << i + firstValue;
			}
		}
	}
	cout << "\n";

}


void regularInput(int array[], long range, long firstValue, long secondValue, string nameOfFile) {

	// begin sort counting and storing the # of times a number is seen into the array
	int input;
	while (cin >> input) {
		if(input > secondValue || input < firstValue) {
			cerr << nameOfFile << ": Invalid input. Integer " << input << " is not in the specified range!\n";
			exit(1);
		}
		array[input-firstValue] = array[input-firstValue] + 1;
	}

	firstFormat(array, range, firstValue);
	secondFormat(array, range, firstValue);
	delete[] array;
}

	
int main(int argc, char* argv[]) {
	
	string nameOfFile = argv[0];

	if (argc < 3) {

		cerr << nameOfFile << ": no range given. this program needs a range of acceptable values!\n";
		exit(1);
	}

	// find the range of values that are valid, initialize the array to size range
	char *end;
	long firstValue = strtol(argv[1], &end, 10);
	if (*end != 0) {
		cerr << nameOfFile << ": First argument needs to be a valid integer!\n";
		exit(1);
	}

	long secondValue = strtol(argv[2], &end, 10);
	if (*end != 0) {
		cerr << nameOfFile << ": Second argument needs to be a valid integer!\n";
		exit(1);
	}
	
	int range = secondValue - firstValue + 1;		// add 1 to the range since range is inclusive
	int *array = new int[range];


	// initialize the array to all 0's
	for (int i = 0; i < range; i++) {

		array[i] = 0;
	}

	// input will be read from cin
	if (argc == 3) {

		regularInput(array, range, firstValue, secondValue, nameOfFile);
	}

	// read from files
	else {
		int x = 3;
		while (x != argc) {
			ifstream in(argv[x]);
			if (!in) {
				cerr << nameOfFile <<": can't open \n" << argv[x];
				exit(1);
			}
			int value;
			while(in >> value) {
				if (value > secondValue || value < firstValue) {
					cerr << nameOfFile << ": Invalid input. " << value << " is not in the specified range!\n";
					exit(1);
				}
				array[value-firstValue] = array[value-firstValue] + 1;
			}
			if (!in.eof()) {
				cerr << nameOfFile << ": Did not reach end of file. One of the files has invalid input!\n";
				exit(1);
			}
			x = x + 1;
		}
		// print out formatted
		firstFormat(array, range, firstValue);
		secondFormat(array, range, firstValue);
		delete[] array;

		
	}
	
	return 0;
}


