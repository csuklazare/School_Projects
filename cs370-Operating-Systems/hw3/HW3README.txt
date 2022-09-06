README FILE

A. Files contained in package:

Initiator.c - This file executes the rest of the executable files created by the Makefile. Contains all fork(), execlp(), and wait() calls to ensure proper function of the program. Also executes read end of the pipe and the read end of the shared memory
Reader.c - Reads a file inputted by Initiator.c, adds the integers up in the file, then returns the total sum of the integers through a pipe
Pell.c - Returns the nth number in the Pell sequence through shared memory
Total.c - Returns the total sum of the first n numbers through shared memory
Composite.c - Returns the nth composite number through shared memory
Makefile - compiles all c files listed above, creates executables for all c files above, can perform a clean to remove all executable files, and creates a tar package to submit
HW2README.txt - The current file we are in, contains description of files as well as answers to questions, and an example of successful output.


B. Use the Makefile in the tar package to build the executables

systemprompt> make build

To remove the executable files use

systemprompt> make clean

OR, to build/clean in one step

systemprompt> make rebuild

To build a new tar package

systemprompt> make package

To run the program use (assuming seed is input1.txt)

systemprompt> ./Initiator input1.txt

This will run the program and generate the outputs.


C. Questions:

	1. The function that creates the pipe is the pipe() function.
 
	2. Since my pipe was created with fd, the read end was defined in the header files as 0 (or the first element of fd) and the write end was defined as 1 (the second element of fd). This created both read and write ends of the pipe to allow me to use it.
  
	3. The function used to map files or devices into memory is mmap().
  
	4. The function used to open a shared memory object is shm_open(). It returns an int which is used as a file descriptor when mmap is called.

D. Example output code:

Using input1.txt with values 5 on the first line and 10 on the second line

I used cat input.txt to show that input.txt contains 5 and 10.

atlanta:~/cs370/hw2$ cat input.txt
5
10
atlanta:~/cs370/hw3$ ./Initiator input1.txt
Initiator[2531334]:  contents read from the read end pipe: 15.
Initiator[2531334] : Created Shared memory "SHM_Pell" with FD: 3
Initiator[2531334] : Created Shared memory "SHM_Composite" with FD: 4
Initiator[2531334] : Created Shared memory "SHM_Total" with FD: 5
Pell[2535279] : Number of terms in Pell series is 15
Pell[2535279] : The first 15 numbers of the Pell sequence are:
0,1,2,5,12,29,70,169,408,985,2378,5741,13860,33461,80782,
Composite[2535280]: First 15 composite numbers are:
4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,
Total[2535281] : Sum = 120
Initiator[2531334] : Pell last number:   80782
Initiator[2531334] : Composite last number:   25
Initiator[2531334] : Total last number:   120


And if we run it again, we get a different output order of Pell, Composite, and Total

atlanta:~/cs370/hw3$ ./Initiator input1.txt
Initiator[2531334]:  contents read from the read end pipe: 15.
Initiator[2531334] : Created Shared memory "SHM_Pell" with FD: 3
Initiator[2531334] : Created Shared memory "SHM_Composite" with FD: 4
Initiator[2531334] : Created Shared memory "SHM_Total" with FD: 5
Composite[2535421]: First 15 composite numbers are:
4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,
Pell[2535420] : Number of terms in Pell series is 15
Pell[2535420] : The first 15 numbers of the Pell sequence are:
Total[2535422] : Sum = 120
0,1,2,5,12,29,70,169,408,985,2378,5741,13860,33461,80782,
Initiator[2531334] : Pell last number:   80782
Initiator[2531334] : Composite last number:   25
Initiator[2531334] : Total last number:   120



Notes:

- I used an exit code of 13 as no pell, composite, or total number could equal 13.
