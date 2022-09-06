#include "Phobic.h"

using namespace std;

Phobic::Phobic(const Phobic &x) {	// copy ctor
	value = x.value;
	afraid = x.afraid;
}

Phobic::Phobic(int y) {
	afraid.push_back(13); 
	setValue(y);
}

Phobic& Phobic::operator=(const Phobic &x) {
	afraid = mergeVectors(afraid, x.afraid);		// add all unique items from x to the current object
	setValue(x.value);	// update value to represent unchanged's value
	
	return *this;
}

Phobic::~Phobic() {
	// empty dtor as memory allocated for vector is automatically freed	
}

[[nodiscard]] Phobic operator+(const Phobic &lhs, const Phobic &rhs) {
	Phobic z(lhs.get()+rhs.get()); 
	z.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	z.setValue(z.get());
	return (z);
}

[[nodiscard]] Phobic operator-(const Phobic &lhs, const Phobic &rhs) {
	Phobic z(lhs.get() - rhs.get());
	z.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	z.setValue(z.get());
	return (z);
}

[[nodiscard]] Phobic operator*(const Phobic &lhs, const Phobic &rhs) {
	Phobic z(lhs.get() * rhs.get());
	z.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	z.setValue(z.get());
	return (z);
}

[[nodiscard]] Phobic operator/(const Phobic &lhs, const Phobic &rhs) {
	if (rhs.get() == 0) {
		error("Division by 0 not allowed!\n");
	}
	Phobic z(lhs.get() / rhs.get());
	z.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	z.setValue(z.get());
	return (z);
}


void operator+=(Phobic &lhs, const Phobic &rhs)  {
	lhs.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	lhs.setValue(lhs.get() + rhs.get());
}
	
void operator-=(Phobic &lhs, const Phobic &rhs)  {
	lhs.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	lhs.setValue(lhs.get()-rhs.get());
}

void operator*=(Phobic &lhs, const Phobic &rhs)  {
	lhs.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	lhs.setValue(lhs.get()*rhs.get());
}

void operator/=(Phobic &lhs, const Phobic &rhs)  {
	if (rhs.get() == 0) {
		error("Division by 0 not allowed!\n");
	}
	lhs.afraid = mergeVectors(lhs.afraid, rhs.afraid);
	lhs.setValue(lhs.get()/rhs.get());
}

[[nodiscard]] bool operator==(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() == rhs.get()) {
		return true;
	}
	return false;
}

[[nodiscard]] bool operator<(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() < rhs.get()) {
		return true;
	}
	return false;
}
[[nodiscard]] bool operator>(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() > rhs.get()) {
		return true;
	}
	return false;
}
[[nodiscard]] bool operator!=(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() != rhs.get()) {
		return true;
	}
	return false;
}
[[nodiscard]] bool operator<=(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() <= rhs.get()) {
		return true;
	}
	return false;
}
[[nodiscard]] bool operator>=(const Phobic &lhs, const Phobic &rhs) {
	if (lhs.get() >= rhs.get()) {
		return true;
	}
	return false;
}
Phobic Phobic::operator<<(int one) {
	if (is_scary(one) == 0) {
		setScary(one);
	}

	setValue(value);
	return *this;
}
[[nodiscard]] int Phobic::get() const {
	return value;
}	
[[nodiscard]] bool Phobic::is_scary(int y) {
	vector<int>::iterator it;
	it = find(afraid.begin(), afraid.end(), y);
	if (it != afraid.end()) {
		return true;
	}
	else {
		return false;
	}
}
vector<int> mergeVectors(const vector<int> &vector1, const vector<int> &vector2) {
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

vector<int> mergeVectors(vector<int> &vector1, vector<int> &vector2) {
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
inline void error(const string& s) {

	throw runtime_error(s);
}
