#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

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
void secondFormat(int array[], long range, int firstValue, string separator = ",") {

	int counter = 0;	
	for (int i = 0; i < range; i++) {
		if (array[i] == 0) {
			continue;
		}
		if (counter == 0) {
			for (int j = 0; j < array[i]-1; j++) {	
				cout << i + firstValue << separator;
			}
			cout << i + firstValue;
			counter = counter + 1;
		}
		else {
			for (int j = 0; j < array[i]; j++) {
				cout << separator << i + firstValue;
			}
		}
	}
	cout << "\n";

}
void printOut(int array[], long range, int firstValue, bool f, bool s, bool c, string separator) {
	if ((f == true) & (s == false)) {
		firstFormat(array, range, firstValue);
	}
	else if ((f == false) & (s == true)) {
		if (c == true) {
			secondFormat(array, range, firstValue, separator);
		}
		else {
			secondFormat(array, range, firstValue);
		}
	}
	else {
		firstFormat(array, range, firstValue);
		if (c == true) {
			secondFormat(array, range, firstValue, separator);
		}
		else {
			secondFormat(array, range, firstValue);
		}
	}
}

void regularInput(int array[], long range, int firstValue, int secondValue, string nameOfFile, string separator, bool f, bool s, bool c) {
	// begin sort counting and storing the # of times a number is seen into the array
	int input;
	while (cin >> input) {
		if(input > secondValue || input < firstValue) {
			cerr << nameOfFile << ": Invalid input. Integer " << input << " is not in the specified range!\n";
			exit(1);
		}
		array[input-firstValue] = array[input-firstValue] + 1;
	}
	
	printOut(array, range, firstValue, f, s, c, separator);
	delete[] array;
}

int main(int argc, char* argv[]) {
	string nameOfFile = argv[0];
	bool f = false;
	bool s = false;
	bool v = false;
	bool r = false;
	bool c = false;
	int opt;
	opterr = 0;
	optopt = 0;
	string inputRange, separator;
	long firstValue, secondValue;
	while ((opt = getopt(argc, argv, "+fsvr:c:")) != -1) {
		switch(opt) {
			case 'f':
				f = true;
				break;
			case 's':
				s = true;
				break;
			case 'v':
				v = true;
				break;
			case 'r':
				if (r == true) {
					cerr << nameOfFile << ": You specified 2 ranges with 2 -r. Specify only 1 range!\n";
					exit(1);
				}
				inputRange = optarg;
				char *end;
				firstValue = strtol(optarg, &end, 10);
				if (*end != '-') {
					cerr << nameOfFile << ": Invalid range! You entered " << optarg << ", please use only numbers and a single '-' to separate them!\n";
					exit(1);
				}
				end += 1;
				secondValue = strtol(end, &end, 10);
				if (*end != 0) {
					cerr << nameOfFile << ": Invalid range! You entered " << optarg << ", please use only numbers and a single '-' to separate them!\n";
					exit(1);
				}
				r = true;
				break;
			case 'c':
				if (c == true) {
					cerr << nameOfFile << ": You specified 2 strings to use instead of a comma. Only specify 1!\n";
					exit(1);	
				}
				separator = optarg;
				c = true;
				break;
			case '?':
				if (optopt == 'c') {
					cerr << nameOfFile << ": You did not give c an argument. Please give c an argument!\n";
				}
				else if (optopt == 'r') {
					cerr << nameOfFile << ": You did not give r a range. Please give r a range!\n";
				}
				else {
					char wrongFlag = optopt;
					cerr << nameOfFile << ": The flag " << wrongFlag << " is invalid. Check your flags to make sure they are either -f, -s, -v, -c (with a string arguemnt), or -r (with range).\n";
				}
				exit(1);
		}
	}
	// check to see if c is true with no s implicity or explicitly
	if (c == true) {
		if ((s == false) & (f == true)) {
			cerr << nameOfFile << ": The -c flag was set, but flag -s is not set implicity/explicity. Please try again with proper flagging!\n";
			exit(1);
		}
	}
	long range;
	if (r == true) {
		range = secondValue - firstValue + 1;		// add 1 to the range since range is inclusive
	}
	else {
		firstValue = 0;
		secondValue = 99;
		range = secondValue - firstValue + 1;
	}
	// make sure range is valid
	if (range < 1) {
		cerr << nameOfFile << ": First value of range bigger than 1st. Illegal range!\n";
		exit(1);	
	}
	int *array = new int[range];
	// initialize the array to all 0's
	for (int i = 0; i < range; i++) {
		array[i] = 0;
	}
	// input will be read from cin
	if (optind == argc) {
		if (v == true) {
			cout << "Reading from standard input\n";
		}
		regularInput(array, range, firstValue, secondValue, nameOfFile, separator, f, s, c);
	}
	// read from files
	else {
		int x = optind;
		while (x != argc) {
			ifstream in(argv[x]);
			if (!in) {
				cerr << nameOfFile <<": can't open " << argv[x] << "\n";
				exit(1);
			}
			int value;
			if (v == true) {
				cout << "Reading from " << argv[x] << "\n";
			}
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
		// print out values
		printOut(array, range, firstValue, f, s, c, separator);
		delete[] array;
	}
}
