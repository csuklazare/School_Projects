#include <iostream>
#include <sstream>
#include<string>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number &operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value = 0;			// default value unless otherwise given
};

istream &operator>>(istream &is, Number &rhs) {
    int n;
    string s;
    is >> n;
    if (is.rdstate() & ios::failbit) {
	is.clear();
	is >> s;
	if (s == "one") {
		n = 1;
	}
	if (s == "two") {
		n = 2;
	}
	if (s == "three") {
		n = 3;
	}
	if (s == "four") {
		n = 4;
	}
	if (s == "five") {
		n = 5;
	}
    }
    rhs = n;
    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}
