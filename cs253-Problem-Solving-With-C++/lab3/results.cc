#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[]) {

	// create vector of type int, and get first integer value into input
	vector<int> vector;
	int input;
	cin >> input;

	// add items to the vector until 0 is entered
	while (input != 0) {
		vector.push_back(input);
		cin >> input;
	}

	// print 1 element of the vector on each line
	for (size_t i = 0; i < vector.size(); i++) {
		cout << vector[i] << "\n";
	}

	// use ifstream to read a specific file
	ifstream in("/etc/resolv.conf");
	string s;
	string output;

	// while there are new lines in the file specified above, add them to a single string, with ending every line with a new line
	while (getline(in, s)) {

		output = output + s + "\n";
		
	}
	cout << output;

	// create a multiset to copy all the characters from the string to it
	multiset<char> multiset;

	// loop through the entire string and add the character to the multiset
	for (size_t i = 0; i < output.size(); i++) {
		multiset.insert(output[i]);
		
	}

	// create a set with parameters of the multiset with an iterator at the beginning, then making it iterate to the end, adding each of the items in between into the set (with no duplicates).
	set<char> set (multiset.begin(), multiset.end());
	
	// print output
	cout << "string: size=" << output.size() << " " << output << "\n";
	
	cout << "set: size=" << set.size() << " ";
	for (char c : set) {
		cout << c;
	}
	cout << "\n";


	cout << "multiset: size=" << multiset.size() << " ";
	for (char d: multiset) {
		cout << d;
	}	
	cout << "\n";


	// QUESTION 7: The sizes for the multiset and the string are the same because a multiset can hold multiples of each character when inputted into it. Since it inserts every character into it, the multiset should have the same size. The set on the other hand does not hold this property, and can only hold 1 of each character. Hence why the size of the set is so much smaller, it has no duplicates. If the multiset and string consisted of only unique characters, then the set would be the same size.
	return 0;
}
