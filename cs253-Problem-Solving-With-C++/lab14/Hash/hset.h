#ifndef HSET_H_INCLUDED
#define HSET_H_INCLUDED

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "hasher.h"
#include "hset_iter.h"

template <typename T, int given_size = 5, typename H = Hasher> // Exercise 1
class hset {
  private:
    static constexpr unsigned table_size=given_size; // Exercise 1
    std::vector<std::list<T>> table;
    

  public:
    using iterator = hset_iter<T>;
    using value_type = T;
    using size_type = size_t;

    hset() : table(table_size) { }
    hset(const hset &) = default;
    hset &operator=(const hset &) = default;
    ~hset() = default;

    void insert(const T &datum) {
	unsigned hashval = H()(datum) % table.size();
	auto &lr = table[hashval];
	if (find(lr.begin(), lr.end(), datum) == lr.end())
	    lr.push_back(datum);
    }
   
// Exercise 2
    bool empty() {
	
	for (size_t i = 0; i < table.size(); i++) {
	    if (table[i].size() > 0) {
		return false;
	    }
	}
	return true;
    }

    // Walk down the hash table, adding up all the sizes.
    size_type size() const {
	size_type total = 0;
	for (const auto &row : table)
	    total += row.size();
	return total;
    }
// Exercise 4
    iterator begin() {
	return iterator(table, 0, 0);
    }
// Exercise 4
    iterator end() {
	return iterator(table, table_size-1, table[table_size-1].size()-1);
    }

    void dump() const {
	for (unsigned i=0; i<table.size(); i++) {
	    std::cout << "table[" << i << "]";
	    for (auto v : table[i]) 
		    std::cout << ' ' << v;
	    std::cout << '\n';
	}
    }
};

#endif /* HSET_H_INCLUDED */
