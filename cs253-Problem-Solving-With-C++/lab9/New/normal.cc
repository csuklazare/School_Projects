#include <iostream>
#include <vector>

using namespace std;

class Foo {
  public:
    double datum;
};

int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    Foo *p = new Foo;
    Foo *q = new Foo;
    vector<Foo> my_vector;
    for (int i = 0; i < 100000000; i++) {
	Foo *t = new Foo;
	my_vector.push_back(*t);
    }
    cout << "p=" << p << '\n'
	 << "q=" << q << '\n';
    delete p;
    delete q;
    return 0;
}
