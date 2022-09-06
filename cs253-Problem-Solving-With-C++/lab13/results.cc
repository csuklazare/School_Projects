#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 42, 84};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';
    cout << "Exercise 1\n";
    string backwards = cbuf;
    reverse(backwards.begin(), backwards.end());
    cout << backwards << '\n';
    cout << "Exercise 2\n";
    transform(primes.begin(), primes.end(), ibuf, [](int n) -> int {return n + 1; });
    for (int i = 0; i < 10; i ++) {
	if (i == 0) {
		cout << ibuf[i];
	}
	else {
		cout << " " << ibuf[i];
	}
    }
    cout << '\n';
    cout << "Exercise 3\n";
    if (any_of(primes.begin(), primes.end(), [](int i){return i % 2 == 0; })) {
	cout << "div 2\n";
	if (any_of(primes.begin(), primes.end(), [](int i){return i % 42 == 0; })) {
		cout << "div 42\n";
	}
    }
    cout << "Exercise 4\n";
    auto p = find(primes.begin(), primes.end(), 13);
    p++;
    cout << *p << '\n';
    cout << "Exercise 5\n";
    int num = count(pi.begin(), pi.end(), 3);
    cout << num << '\n';
    cout << "Exercise 6\n";
    int numTwo = count_if(pi.begin(), pi.end(), [](int i) {return i < 5; });
    cout << numTwo << '\n';
    cout << "Exercise 7\n";
    auto max = max_element(pi.begin(), pi.end());
    cout << *max << '\n';
    cout << "Exercise 8\n";
    sort(pi.begin(), pi.end());
    for (size_t i = 0; i < pi.size(); i++) {
	if (i == 0) {
		cout << pi[i];
	}
	else {
		cout << " " << pi[i];
	}
    }
    cout << '\n';
    cout << "Exercise 9\n";
    auto lower = lower_bound(pi.begin(), pi.end(), 7);
    cout << lower - pi.begin() << '\n';
    cout << "Exercise 10\n";
    auto front = cbegin(powers);
    auto back = cend(powers);
    auto end = set_intersection(pi.begin(), pi.end(), front, back, ibuf);
    for (int i = 0; i < (end-&ibuf[0]); i++) {
	if (i == 0) {
		cout << ibuf[i];
	}
	else {
		cout << " " << ibuf[i];
	}
    }
    cout << '\n';
}
