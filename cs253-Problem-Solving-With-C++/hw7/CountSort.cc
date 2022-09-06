#include "CountSort.h"

using namespace std;

CountSort::CountSort(int x, int y) {
	high = y;
	low = x;
	maxSize = y-x+1;
	data = new int[maxSize];
	for (int i = 0 ; i < maxSize; i++) {
		data[i] = 0;
	}
}
CountSort::CountSort(const initializer_list<int> &il) {
	*this = il;
}
CountSort &CountSort::operator=(const initializer_list<int> &il) {
	clear();
	for (auto it = il.begin(); it != il.end(); it++) {
		insert(*it);
	}
	return *this;
}
CountSort::~CountSort() {
	clear();
	delete[] data;
}
void CountSort::insert(int x) {
	if (x < low || x > high) {
		string s = "Error: " + to_string(x) + " is out of the acceptable range. Please enter numbers only in the range " + to_string(low) + " to " + to_string(high)  + ".\n";
		throw out_of_range(s);
	}
	else {
		int index = x - low;
		data[index] = data[index] + 1;
	}
}

int CountSort::operator()(int x) const {
	if (x >= maxSize) {
		string s = "Error: " + to_string(x) + " is not a valid index. Please enter a valid index between 0 and " + to_string(maxSize-1) + ".\n";
		throw out_of_range(s);
	}
	else {
		return data[x];
	}
}
int CountSort::operator[](int x) const {
	int runningSum = 0;
	int returnValue = 0;
	if (x > size()) {
		string s = "Error: " + to_string(x) + " is not a valid index. Please enter a valid index below " + to_string(size()) + ".\n";
		throw out_of_range(s);
	}
	else {
		for (int i = 0; i < maxSize; i++) {
			runningSum += data[i];
			if (runningSum > x) {	
				returnValue = i+low;
				break;
			}
		}
		return returnValue;
	}
}
int CountSort::min() const {
	return low;
}
int CountSort::max() const {
	return high;
}
int CountSort::width() const {
	return high-low;
}
int CountSort::size() const {
	int runningSum = 0;
	for (int i = 0; i < maxSize; i++) {
		runningSum += data[i];
	}
	return runningSum;
}
bool CountSort::empty() const {							
	for (int i = 0; i < maxSize; i++) {
		if (data[i] > 0) {
			return false;
		}
	}
	return true;
}

void CountSort::clear() {
	for (int i = 0; i < maxSize; i++) {
		data[i] = 0;
	}
}
CountSort::iterator CountSort::begin() const {
	for (int i = 0; i < maxSize; i++) {
		if (data[i] > 0) {
			return CountSort::iterator(&data[i], low + i, high);
		}
	}
	return CountSort::iterator(&data[0], low, high);
}
CountSort::iterator CountSort::end() const {
	for (int i = maxSize - 1; i >= 0; i--) {
		if (data[i] > 0) {
			return CountSort::iterator(&data[i+1], low + i, high); 
		}
	}
	return CountSort::iterator(&data[0], low, high);

}
