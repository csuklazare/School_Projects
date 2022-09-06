#include "Phobic.h"

using namespace std;

Phobic::Phobic(int y) {
	afraid.push_back(13); 
	setValue(y);
}

Phobic::Phobic(const Phobic &x) {	// copy ctor
	value = x.value;
	afraid = x.afraid;
}

Phobic& Phobic::operator=(const Phobic &x) {
	afraid = mergeVectors(afraid, x.afraid);		// add all unique items from x to the current object
	setValue(x.value);	// update value to represent unchanged's value
	
	return *this;
}

Phobic::~Phobic() {
	// empty dtor as memory allocated for vector is automatically freed	
}

Phobic Phobic::add(const Phobic &x) const {
	Phobic z(value+x.get());
	z.afraid = mergeVectors(afraid, x.afraid);
	z.setValue(z.get());
	return (z);
}

Phobic Phobic::sub(const Phobic &x) const {
	Phobic z(value - x.value);
	z.afraid = mergeVectors(afraid, x.afraid);
	z.setValue(z.get());
	return (z);
}

Phobic Phobic::mul(const Phobic &x) const {
	Phobic z(value * x.value);
	z.afraid = mergeVectors(afraid, x.afraid);
	z.setValue(z.get());
	return (z);
}

Phobic Phobic::div(const Phobic &x) const {
	Phobic z(value / x.value);
	z.afraid = mergeVectors(afraid, x.afraid);
	z.setValue(z.get());
	return (z);
}

void Phobic::add_to(const Phobic &x)  {
	value = value + x.value;
	afraid = mergeVectors(afraid, x.afraid);
	setValue(value);
}
	
void Phobic::sub_from(const Phobic &x)  {
	value = value - x.value;
	afraid = mergeVectors(afraid, x.afraid);
	setValue(value);
}

void Phobic::mul_by(const Phobic &x)  {
	value = value * x.value;
	afraid = mergeVectors(afraid, x.afraid);
	setValue(value);
}

void Phobic::div_by(const Phobic &x)  {
	value = value / x.value;
	afraid = mergeVectors(afraid, x.afraid);
	setValue(value);
}

bool Phobic::eq(const Phobic &x) const {
	if (value == x.value) {
		return true;
	}
	else {
		return false;
	}
}

bool Phobic::lt(const Phobic &x) const {
	if (value < x.value) {
		return true;
	}
	else {
		return false;
	}
}

int Phobic::get() const {
	return value;
}

void Phobic::make_scary(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten) {
	if (is_scary(one) == 0) {
		setScary(one);
	}

	if (is_scary(two) == 0) {
		setScary(two);
	}
	
	if (is_scary(three) == 0) {
		setScary(three);
	}

	if (is_scary(four) == 0) {
		setScary(four);
	}

	if (is_scary(five) == 0) {
		setScary(five);
	}

	if (is_scary(six) == 0) {
		setScary(six);
	}
	
	if (is_scary(seven) == 0) {
		setScary(seven);
	}
	
	if (is_scary(eight) == 0) {
		setScary(eight);
	}
	
	if (is_scary(nine) == 0) {
		setScary(nine);
	}

	if (is_scary(ten) == 0) {
		setScary(ten);
	}
	setValue(value);
}
	
bool Phobic::is_scary(int y) {
	vector<int>::iterator it;
	it = find(afraid.begin(), afraid.end(), y);
	if (it != afraid.end()) {
		return true;
	}
	else {
		return false;
	}
}
vector<int> Phobic::mergeVectors(const vector<int> &vector1, const vector<int> &vector2) const {
	vector<int> returnVector;
	vector<int>::iterator it;

	for (size_t i = 0; i < vector1.size(); i++) {
		returnVector.push_back(vector1[i]);
	}
	for (size_t i = 0; i < vector2.size(); i++) {
		it = find(returnVector.begin(),returnVector.end(), vector2[i]);
		if (it != returnVector.end()) {
			continue;
		}
		else {
			returnVector.push_back(vector2[i]);
		}
	}

	return returnVector;
}

vector<int> Phobic::mergeVectors(vector<int> &vector1, vector<int> &vector2) {
	vector<int> returnVector;
	vector<int>::iterator it;

	for (size_t i = 0; i < vector1.size(); i++) {
		returnVector.push_back(vector1[i]);
	}
	for (size_t i = 0; i < vector2.size(); i++) {
		it = find(returnVector.begin(),returnVector.end(), vector2[i]);
		if (it != returnVector.end()) {
			continue;
		}
		else {
			returnVector.push_back(vector2[i]);
		}
	}
	return returnVector;
}

void Phobic::setValue(int newValue) {

	while(is_scary(newValue) == 1) {
		newValue++;
	}
	value = newValue;
}

void Phobic::setScary(int scary) {
	if (scary == INT_MAX) {
		
	}
	else {
		afraid.push_back(scary);
	}
}
