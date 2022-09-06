README FILE

A. Files contained in package:

Initiator.c - This file executes the rest of the executable files created by the Makefile. Contains all fork(), execlp(), and wait() calls to ensure proper function of the program.
Pell.c - Returns the nth number in the Pell sequence
Total.c - Returns the total sum of the first n numbers
Composite.c - Returns the nth composite number
Makefile - compiles all c files listed above, creates executables for all c files above, can perform a clean to remove all executable files, and creates a tar package to submit
HW2README.txt - The current file we are in, contains description of files as well as answers to questions, and an example of successful output.


B. Use the Makefile in the tar package to build the executables

systemprompt> make build

To remove the executable files use

systemprompt> make clean

OR, to build/clean in one step

systemprompt> make rebuild

To run the program use (assuming seed is input.txt)

systemprompt> ./Initiator input.txt

This will run the program and generate the outputs.


C. Questions:

	1. What is the return value for the fork() in a child process?

		A. The return value for the fork() in a child process is the child's PID.

	2. Give a reason for the fork() to fail?

		A. The fork could fail if there is not enough memory left to create another child process. 

	3. How many of the least significant bits of the status does WEXITSTATUS return?

		A. It returns 8 bits.

	4. Which header file has to be included to use the WEXITSTATUS?

		A. The header file <sys/wait.h>. 

	5. In this program, are we doing a sequential processing or a concurrent processing with respect to the child processes? Sequential processing is when only one of the child processes is running at one time, and concurrent processing is when more than one child process can be running at the same time.

		A. This program is sequential processing, because each child process ends before the next one begins.

	6. Is it possible to have any anomalies in the output from child process and the output from parent process? Provide a reason for that possible situation.

		A. Yes, since the WEXITSTATUS only returns exit status's to a max of 255, any integer value over 255 will cause an invalid value to be returned as we can see with running Pell.c with 10. It returns 217 when it should be returning 985.

D. Example output code:

Using input.txt with values 10 on the first line and 15 on the second line

I used cat input.txt to show that input.txt contains 10 and 15.


atlanta:~/cs370/hw2$ cat input.txt
10
15
atlanta:~/cs370/hw2$ ./Initiator input.txt
Initiator[3823215]: Forked process with ID 3823216.
Initiator[3823215]: Waiting for Process [3823216].
Pell[3823216] : Number of terms in Pell series is 10
Pell[3823216] : The first 10 numbers of the Pell sequence are:
0,1,2,5,12,29,70,169,408,985,
Initiator: Child process 3823216 returned 217.
Initiator[3823215]: Forked process with ID 3823217.
Initiator[3823215]: Waiting for Process [3823217].
Composite[3823217]: First 10 composite numbers are
:4,6,8,9,10,12,14,15,16,18,
Initiator: Child process 3823217 returned 18.
Initiator[3823215]: Forked process with ID 3823218.
Initiator[3823215]: Waiting for Process [3823218].
Total[3823218] : Sum = 55
Initiator: Child process 3823218 returned 55.
Initiator: Pell: 217
Initiator: Composite: 18
Initiator: total Count: 55
Initiator[3823215]: Forked process with ID 3823219.
Initiator[3823215]: Waiting for Process [3823219].
Pell[3823219] : Number of terms in Pell series is 15
Pell[3823219] : The first 15 numbers of the Pell sequence are:
0,1,2,5,12,29,70,169,408,985,2378,5741,13860,33461,80782,
Initiator: Child process 3823219 returned 142.
Initiator[3823215]: Forked process with ID 3823220.
Initiator[3823215]: Waiting for Process [3823220].
Composite[3823220]: First 15 composite numbers are
:4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,
Initiator: Child process 3823220 returned 25.
Initiator[3823215]: Forked process with ID 3823221.
Initiator[3823215]: Waiting for Process [3823221].
Total[3823221] : Sum = 120
Initiator: Child process 3823221 returned 120.
Initiator: Pell: 142
Initiator: Composite: 25
Initiator: total Count: 120
atlanta:~/cs370/hw2$


Notes:

- I used an exit code of 13 as no pell, composite, or total number could equal 13.