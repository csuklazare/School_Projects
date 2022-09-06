#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED

#include <dirent.h>
#include <string>

// Normally, I’d have DirectoryIterator be a nested class, Directory::iterator,
// to avoid namespace pollution.  However, this is easier to read.

class DirectoryIterator {
  public:
    DirectoryIterator() = default;
    DirectoryIterator(DIR *, std::string optional);	// FIX #3, described in .cc file
    DirectoryIterator &operator++();			// FIX #2, described in .cc file
    std::string operator*() const;
    bool operator!=(const DirectoryIterator &) const;
  private:
    DIR *dp = nullptr;
    DirectoryIterator &wanted();			// FIX #2, described in .cc file
    std::string name;
    std::string match;					// FIX #3, string to match if provided
};

class Directory {
  public:
    typedef DirectoryIterator iterator;
    Directory() = delete;		// not really necessary
    Directory(const char dirname[], std::string optional = "match me"); // FIX #3, described in .cc file
    ~Directory();
    iterator begin() const;				// FIX #3, described in .cc file
    iterator end() const;
  private:
    DIR *dp;				// null if open failed
    std::string match;					// FIX #3, string to match if provided
};

#endif /* DIRECTORY_H_INCLUDED */
