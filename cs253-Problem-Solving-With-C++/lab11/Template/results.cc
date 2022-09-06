#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    friend ostream &operator<<(ostream &os, const BarGraph<T> &graph) {
	for (const auto &val : graph.data)
	    os << right << setw(10) << val.first << ' '
	       << string(val.second, '*') << '\n';
        os << '\n';
	return os;
    }
  private:
    map<T, unsigned> data;

};
template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend ostream &operator<<(ostream &os, const BarGraph<bool> &graph) {
        return os << "     false " << string(graph.false_count, '*') << "\n"
                     "      true " << string(graph.true_count,  '*') << "\n\n";
    }
};
template <>
class BarGraph<char> {
  char array[128];
  public:
	void operator+=(char x) {
		int value = x;
		array[value]++;
	}
	void operator+=(string x) {
		for (size_t i = 0; i < x.size(); i++) {
			int value = x[i];
			array[value]++;
		}
	}
	friend ostream &operator<<(ostream &os, const BarGraph<char> &graph) {
		for (int i = 0 ; i < 128; i++) {
			if (graph.array[i] > 0) {
				char c = i;
				os << right << setw(10) << c << ' '
				   << string(graph.array[i], '*') << '\n';
			}
		}
		os << '\n';
		return os;
	}	
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}
