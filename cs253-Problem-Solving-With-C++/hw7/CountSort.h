#ifndef COUNTSORT_H
#define COUNTSORT_H

#include <initializer_list>
#include <string>
#include <stdexcept>
#include <cassert>
#include <iostream>

class CountSort {
	int *data;
	int maxSize;
	public:
		CountSort(int x, int y); 	// ctor
		CountSort(const std::initializer_list<int> &il);	// initializer list
		CountSort &operator=(const std::initializer_list<int> &il);
		~CountSort();
		void insert(int x);			// insert a number into CountSort object
		int operator()(int x) const;		// return the count of the specified index
		int operator[](int x) const;		// return the nth int from the object in sorted order
		int min() const;			// return min value of CountSort object
		int max() const;			// return max value of CountSort object
		int width() const;			// return number of int values object can hold
		int size() const;			// return how many ints are currently stored
		bool empty() const;				// return true iff container is empty
		void clear();				// clear the container
		class iterator {
			public:
				iterator(int *ptr, int val, int highest) : p(ptr), value(val), max(highest) {counter = 1; }
				iterator(const iterator &it) : p(it.p), value(it.value), counter(it.counter), max(it.max) {}
				int &operator*() {
					return value;
				}
				iterator &operator++() {		// preincrement
					if (counter < *p) {
						counter++;
					}
					else {
						counter = 1;
						p++;
						value++;
						while (value < max && *p == 0) {
							p++;
							value++;
						}
					}
					return *this;
				}
				iterator operator++(int) {		//post increment
					const auto temp = *this;
					++*this;
					return temp;
				}
				bool operator==(const iterator &rhs) const {
					return p==rhs.p;
				}
				bool operator !=(const iterator &rhs) const {
					return !(*this == rhs);
				}
				iterator operator=(const iterator &rhs) {
					p = rhs.p;
					value = rhs.value;
					counter = rhs.counter;
					max = rhs.max;
					return *this;
				}
			private:
				int *p;
				int value;
				int counter;
				int max;
		};
		iterator begin() const;			// return object of type CountSort::iterator that points to smallest int stored
		iterator end() const;				// return object of type CountSort::iterator that points 1 past max int stored
		
	private:
		
		int high;
		int low;

};
// FREE FUNCTIONS



#endif
