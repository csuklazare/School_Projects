# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /s/chopin/g/under/fisher25/cs253/hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/chopin/g/under/fisher25/cs253/hw3

# Utility rule file for hw1.tar.

# Include the progress variables for this target.
include CMakeFiles/hw1.tar.dir/progress.make

CMakeFiles/hw1.tar:
	tar -cf hw1.tar *.cc CMakeLists.txt

hw1.tar: CMakeFiles/hw1.tar
hw1.tar: CMakeFiles/hw1.tar.dir/build.make

.PHONY : hw1.tar

# Rule to build all files generated by this target.
CMakeFiles/hw1.tar.dir/build: hw1.tar

.PHONY : CMakeFiles/hw1.tar.dir/build

CMakeFiles/hw1.tar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw1.tar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw1.tar.dir/clean

CMakeFiles/hw1.tar.dir/depend:
	cd /s/chopin/g/under/fisher25/cs253/hw3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/chopin/g/under/fisher25/cs253/hw3 /s/chopin/g/under/fisher25/cs253/hw3 /s/chopin/g/under/fisher25/cs253/hw3 /s/chopin/g/under/fisher25/cs253/hw3 /s/chopin/g/under/fisher25/cs253/hw3/CMakeFiles/hw1.tar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw1.tar.dir/depend

