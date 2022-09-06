README
======

A. This package includes the following files. In your own readme file, modify the information as needed.

Initiator.c - This intitates the worker.c file and prints the correct output to the terminal.
Worker.c - This performs multiple functions in order to calculate the floating point average of the running ratio.
Worker.h - This header file allows Initiator.c to access Worker.c and call its functions.
Makefile - This file compiles the code in one working package. It also allows the creation of a tar package for submission.
HW1README.txt - This file is the one we are currently in. It contains answers to questions as well as valgrind output for both no memory leaks and memory leaks.


B. Use your designed makefile 
To compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming seed is 3) 

systemprompt> ./Initiator 3

which will run the program and generate the outputs.


C. Answer the following questions (1 point each, select/type the right answer).

  1. What is the main difference between Malloc() and Calloc()?
      a. The main difference between these two is calloc assigns all of the memory the value 0, whereas Malloc assigns it to be Null.
  2. When dynamically allocating an integer array, Malloc takes the number of elements as the input? –     True/False
      a. This is true. Calloc also does as well.
  3. What happens if memory is not properly freed after using dynamic memory allocation?
      a. Memory can leak, and if enough leaks it can cause software issues.
  4. What is the purpose of the headerfile Worker.h and Why is Initiator.h not necessary?
      a. Worker.h is necessary to allow Initiator.c to access the functions in Worker.c. Initiator.h is not necessary as Worker.c doesn't need to access Initiator.c.
  5. Describe the * and & operators in the context of pointers and references?
      a. * is a pointer to a variable at an address. & is a reference to a value at the address. So, when int* x = &y, x is pointing to the address where y's variable is being held. To access the actual value, it would be *x.
      
      
Valgrind output:


With no memory leaks:

atlanta:~/cs370/HW1$ valgrind  --leak-check=full ./Initiator 7
==2403646== Memcheck, a memory error detector
==2403646== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2403646== Using Valgrind-3.16.0 and LibVEX; rerun with -h for copyright info
==2403646== Command: ./Initiator 7
==2403646==
[Initiator]: With seed: 7
[Worker]: Number of iterations is: 77
[Worker]: Iteration with maximum fully divisible elements is 59
[Initiator]: Running ratio: 0.122461
==2403646==
==2403646== HEAP SUMMARY:
==2403646==     in use at exit: 0 bytes in 0 blocks
==2403646==   total heap usage: 78 allocs, 78 frees, 38,872 bytes allocated
==2403646==
==2403646== All heap blocks were freed -- no leaks are possible
==2403646==
==2403646== For lists of detected and suppressed errors, rerun with: -s
==2403646== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



With memory leaks:

atlanta:~/cs370/HW1$ valgrind  --leak-check=full ./Initiator 7
==2405246== Memcheck, a memory error detector
==2405246== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2405246== Using Valgrind-3.16.0 and LibVEX; rerun with -h for copyright info
==2405246== Command: ./Initiator 7
==2405246==
[Initiator]: With seed: 7
[Worker]: Number of iterations is: 77
[Worker]: Iteration with maximum fully divisible elements is 59
[Initiator]: Running ratio: 0.122461
==2405246==
==2405246== HEAP SUMMARY:
==2405246==     in use at exit: 37,848 bytes in 77 blocks
==2405246==   total heap usage: 78 allocs, 1 frees, 38,872 bytes allocated
==2405246==
==2405246== 37,848 bytes in 77 blocks are definitely lost in loss record 1 of 1
==2405246==    at 0x4C3721A: calloc (vg_replace_malloc.c:760)
==2405246==    by 0x40092A: get_running_ratio (in /s/chopin/g/under/fisher25/cs370/HW1/Initiator)
==2405246==    by 0x400761: main (in /s/chopin/g/under/fisher25/cs370/HW1/Initiator)
==2405246==
==2405246== LEAK SUMMARY:
==2405246==    definitely lost: 37,848 bytes in 77 blocks
==2405246==    indirectly lost: 0 bytes in 0 blocks
==2405246==      possibly lost: 0 bytes in 0 blocks
==2405246==    still reachable: 0 bytes in 0 blocks
==2405246==         suppressed: 0 bytes in 0 blocks
==2405246==
==2405246== For lists of detected and suppressed errors, rerun with: -s
==2405246== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

