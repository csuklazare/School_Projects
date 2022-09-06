#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

// FIX #3, passing matching string to Directory Iterator
DirectoryIterator::DirectoryIterator(DIR *dp_arg, string optional) : dp(dp_arg) {
    match = optional;
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

// FIX #2 is here, where we check the file names in the wanted() method.
DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    return this->wanted();
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}

// FIX #2 and FIX #3, FIX #3 is the if-else statement, where we check to see if an argument was given or not to the Directory constructor
DirectoryIterator &DirectoryIterator::wanted() {
    if (match == "match me") {
	    while (auto p = readdir(dp)) {
		name = p->d_name;
		if (name == ".") {
		    continue;
		}
		if (name == "..") {
		    continue;
		}
		return *this;
 	   }
 	   dp = nullptr;
   	   return *this;
    }
    else {
	    while (auto p = readdir(dp)) {
		name = p->d_name;
		if (name.find(match) == string::npos) {
		    continue;
		}
		if (name == ".") {
		    continue;
		}
		if (name == "..") {
		    continue;
		}
		return *this;
	    }
	    dp = nullptr;
	    return *this;
	}
}

//////////////// Directory methods

// FIX #1 and #3 are both incorporated into this. Fix #1 is the if statement and the throw statemenet, Fix #3 is the match = optional, to get the string to match.
Directory::Directory(const char dirname[], string optional) : dp(opendir(dirname)) { if (dp == nullptr) { throw runtime_error("Error: Directory name invalid \n"); } match = optional; {}
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);			//   should we close it.
}
// FIX #3 also here, to pass the matching string to the Directory Iterator Constructor
Directory::iterator Directory::begin() const {
    return iterator(dp, match);
}

Directory::iterator Directory::end() const {
    return iterator();
}

