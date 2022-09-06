#include "Oval.h"
#include "Oval.h"       // I meant to do that.
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
 
using namespace std;
 
// Return a string with all the elements of this container.
template <typename T>
string cat(const T &container, string separator = "") {
    ostringstream oss;
    bool first = true;
    for (size_t i=0; i<container.size(); i++) {
        if (!first)
            oss << separator;
        first = false;
        oss << container[i];
    }
    return oss.str();
}
 
// case-independent comparison functor
class Fold {
  public:
    bool operator()(char a, char b) const {
        return tolower(a) == tolower(b);
    }
};
 
int main() {
    vector<short> initial_values = {123, 11, 22, 123, 33, 22, 123};
    Oval<int> o(initial_values.begin(), initial_values.end());
    cout << cat(o, ",") << '\n';
    auto count = o.erase(123);
    assert(count == 3);
    cout << "Erased " << count << " of 123: " << cat(o, ",") << '\n';
    count = o.erase(666);
    cout << "Erased " << count << " of 666: " << cat(o, ",") << '\n';
    assert(count == 0);
    auto n = o.find(22); cout << "find 22: " << cat(o, ",") << '\n';
    assert(n == 0);
    n = o.find(33); cout << "find 33: " << cat(o, ",") << '\n';
    assert(n == 1);
    n = o.find(99); cout << "find 99: " << cat(o, ",") << '\n';
    assert(n == -1);
 
    for (auto target : {11,22,66})
        cout << "count(" << target << ")=" << o.count(target) << '\n';
 
    string s = "BONEhea";
    Oval<char, 2, Fold> ov(s.begin(), s.end());
    ov.push_back('d');
    cout << cat(ov) << '\n';
    assert(ov.count('e') == 2);
    assert(ov.count('&') == 0);
    n = ov.find('e');
    assert(n == 1);
    assert(cat(ov) == "BEONhead");
    n = ov.find('%');
    assert(n == -1);
    assert(cat(ov) == "BEONhead");
    n = ov.find('D');
    cout << cat(ov) << '\n';
    assert(n == 5);
    assert(cat(ov) == "BEONhdea");
    n = ov.erase('e');
    assert(n == 2);
    assert(cat(ov) == "BONhda");
 
    cout << cat(ov) << '\n';
    Oval<int, 4> test(initial_values.begin(), initial_values.end());
    cout << cat(test, ",") << '\n';
    n = test.find(22);
    cout << n << '\n';
    assert(n==0);
    n = test.size();
    assert(n==7);
    assert(test[1]==123);
    assert(test[6]==123);
    test.push_back(100);
    test.clear();
    assert(test.size() == 0);
    
    cout << "Success!\n";
}
