#ifndef OVAL_H
#define OVAL_H


#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>


template<typename Tx, int defaultFindValue = 1, typename Ty = std::equal_to<Tx>>
class Oval {
	public:
		std::vector<Tx> data;
		int findValue = defaultFindValue;
		Ty cmp;
		Oval() {}					// default ctor
		template<typename Iter>
		Oval(Iter start, Iter last) { for (auto it = start; it != last; it++) { data.push_back(*it); } }	// ctor that takes iterators
		Oval(const Tx &x) { data = x.data; }		// copy ctor
		Oval& operator=(const Tx &x) { data = x.data; return *this; }	// assignment operator
		~Oval() {}
		size_t size() const { return data.size(); }
		int find(const Tx &value) { int counter = 0; int returnValue = -1; for (size_t i = 0; i < data.size(); i++, counter++) { if (cmp(value,data[i])) { if (counter-findValue < 0) { data.insert(data.begin(), data[i]); data.erase(data.begin()+i); returnValue = 0; break; } else { data.insert(data.begin()+i-findValue, data[i]); data.erase(data.begin()+i+1); returnValue = i-findValue;  break; }}} return returnValue; }
		size_t count(const Tx &value) const { int counter = 0; for (size_t i = 0; i < data.size(); i++) { if (cmp(value,data[i])) { counter+= 1; }} return counter; }
		void push_back(const Tx &value) { data.push_back(value); }
		int position(const Tx &value) { int returnValue = -1; for (size_t i = 0; i < data.size(); i++) { if (cmp(value,data[i])) { returnValue = 1; data.erase(data.begin()+i); break; } } return returnValue; }
		size_t erase(const Tx &value) { int counter = 0; while (position(value) != -1) { counter += 1; } return counter; }
		void clear() { data.clear(); }
		Tx &operator[](size_t x) { return data[x]; }
		const Tx &operator[](size_t x) const { return data[x]; }
};



#endif
