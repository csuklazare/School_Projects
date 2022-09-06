#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for advance()

// Each hset_iter contains a reference to its associated hash,
// and an int indicating progress within the hash.

template <typename T>
class hset_iter {
  private:
    using table_t = typename std::vector<std::list<T>>;
    const table_t &parent;  // reference to the hash table we’re iterating over
    size_t vector_index;		    // how far along we are.  0=first item
    size_t list_index;

  public:
    hset_iter(table_t &table, int n, int m) : parent(table), vector_index(n), list_index(m) { }

    bool operator==(const hset_iter &rhs) const {
	return list_index == rhs.list_index;
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
	auto it = parent[vector_index].begin();
	advance(it, list_index);
	return *it;
    }

    // Pre-increment
    void operator++() {
	if (parent[vector_index].size() == 0) {
		vector_index++;
		list_index = 0;
	}
	else if (list_index == parent[vector_index].size()-1) {
		vector_index++;
		list_index = 0;
	}	
	else {
		++list_index;
	}
    }
};

#endif /* HSET_ITER_H_INCLUDED */
