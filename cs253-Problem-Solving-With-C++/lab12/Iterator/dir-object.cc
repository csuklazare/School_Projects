#include <iostream>
#include "Directory.h"

using std::cout;

int main() {
    try {		// one part of fix #1
	Directory dir(".");
	for (auto name : dir)
		cout << "Filename: " << name << '\n';
    }			// catch statement for FIX #1
    catch (std::runtime_error &re) {
	cout << re.what();
    }
}
