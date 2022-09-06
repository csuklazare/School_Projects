# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   The make command reads the Makefile, figures out what files are out of date, and runs the appropriate rules to update those files.
# 
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Hi from main at main.cc:15
#               Hi from foo at foo.cc:14
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   None of the files in the Makefile have been altered, hence there was nothing to update
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   The program small was remade. the rm small; command removes the program small by calling the definition of the rule clean. The semi-colon signifies end of a command line. Then, the make com			mand remakes the small program by calling all necessary rules.
#
#  6) Command:  rm foo.o; make 
#     Question: What got remade, and why?
#     Answer:   rm foo.o removes the foo.o file by calling the definition of the rule clean. When make is called, it remakes foo.o and small because since small relies on foo.o, when foo.o is remade, small 			has to be remade as well to represent the changed foo.o file.
#
#  7) Command:  make clean 
#     Question: What did that do?
#     Answer:   The make clean command calls the clean rule in the Makefile, which removes all .o files of type .o and the small program.
#
#  8) Command:  make 
#     Question: What got remade, and why?
#     Answer:   Both main.o and foo.o were remade, and then the small program was made. These were all made because they were the only files/program that needed updated when make was called.
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   Main.o depends on foo.h because main.cc has foo.h as a specified header file. This needs to be included when making the main.o file sinec main.o is created from main.cc.
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   It fails the call because the Makefile specifies the only files it can "make" is foo.cc and main.cc. To compile the bar files, you would need to add a bar.o option with bar.cc and bar.h as 			the compiling files.
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   I updated the Makefile with a few changes. In the small rule, I added the bar.o to it that way when small is called when make is typed, it will command small to run the bar.o rule as well. 			I then created the bar.o rule which is the same as the other two rules of main.o and foo.o. It creates the bar.o file, which is then used to create the small program.
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   Nothing happened, as nothing within any of the programs was changed. Hence, make didn't need to update anything.
#
# 13) Command:  Force a rebuild with: make clean; make 
#     Question: What’s new about the commands executed?
#     Answer:   The commands executed now include all of the flags specified in CXXFLAGS, which are all g++ flags.
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   The make clean command does not create a file titled "clean". It calls the rule clean to clean the directory of all .o files and the program small. When ls -l clean is called, it fails as t			here is no file titled clean since no file was made.
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o foo.o bar.o -o small

main.o: main.cc foo.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h
	$(CXX) $(CXXFLAGS) -c foo.cc

bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc

clean:
	-rm -f small *.o
