README FILE

A. Files contained in package:

sch.py - File that contains the code for the entire assignment. Given an input .csv file, it will output a FCFS, PS, and a Round Robin schedule. It will also print charts detailing the wait time and turnaround time of each process. For round robin, the time quantum is an argument given on the command line of the terminal.

HW4README.txt - The file we are currently in. Contains details about the program, answers to the questions, and a sample output.


B. To run the program use (assuming .csv is processinfo.csv and time quantum is 4)

systemprompt> python3 sch.py processinfo.csv 4

This will run the program and generate the outputs.


C. Questions:

	1. The shortest remaining time first scheduling could be either non-preemptive or preemptive. It depends on the scheduling requirements of the project.
 
	2. The 5 different states a process can be in scheduling is new, ready, running, waiting, and terminated.
  
	3. Shortest job first is like priority scheduling with the priority based on duration/length/burst of the process.
  
	4. Convoy effect is the primary disadvantage of First Come First Serve Scheduling algorithm.

	5. A multilevel feedback queue prevents starvation by updating priority of processes in the queue that have been waiting too long. For example, if a process is priority 4, then a bunch of processes get executed before it, and the process at priority 4 is never reached, then the priority of the process will be updated to be higher priority the longer it waits.

D. Example output code:

The code below shows sample output with using processinfo.csv and time quantum of 4.

I used cat processinfo.csv to show the contents of the csv file.

snowmass:~/cs370/hw4$ cat processinfo.csv
ProcessID,Arrival Time,Burst Time,Priority
3,0,2,2
2,0,5,4
1,10,8,1
4,10,5,3snowmass:~/cs370/hw4$ python3 sch.py processinfo.csv 4
---------------- FCFS ----------------
Process ID | Waiting Time | Turnaround Time
     1     |      0       |       8
     2     |      0       |       5
     3     |      5       |       7
     4     |      8       |       13

Gantt Chart is:
[  0   ]--  2   --[  5   ]
[  5   ]--  3   --[  7   ]
[  7   ]-- IDLE --[  10  ]
[  10  ]--  1   --[  18  ]
[  18  ]--  4   --[  23  ]

Average Waiting Time: 3.25
Average Turnaround Time: 8.25
Throughput:  0.17391304347826086


----------------- PS -----------------
Process ID | Waiting Time | Turnaround Time
     1     |      0       |       8
     2     |      2       |       7
     3     |      0       |       2
     4     |      8       |       13

Gantt Chart is:
[  0   ]--  3   --[  2   ]
[  2   ]--  2   --[  7   ]
[  7   ]-- IDLE --[  10  ]
[  10  ]--  1   --[  18  ]
[  18  ]--  4   --[  23  ]

Average Waiting Time: 2.5
Average Turnaround Time: 7.5
Throughput:  0.17391304347826086


----------------- Round Robin -----------------
Process ID | Waiting Time | Turnaround Time
     1     |      4       |       12
     2     |      2       |       7
     3     |      4       |       6
     4     |      8       |       13

[  0   ]--  2   --[  4   ]
[  4   ]--  3   --[  6   ]
[  6   ]--  2   --[  7   ]
[  7   ]-- IDLE --[  10  ]
[  10  ]--  1   --[  14  ]
[  14  ]--  4   --[  18  ]
[  18  ]--  1   --[  22  ]
[  22  ]--  4   --[  23  ]

Average Waiting Time: 4.5
Average Turnaround Time: 9.5
Throughput:  0.17391304347826086