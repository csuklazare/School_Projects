README
======

A. - This package includes the following files.

|-- Invoker.java [This is the driver program which will be used to create an instance of the Circular buffer, and create and wait for one thread of producer and one or more threads of and consumer.] (Skeleton Code provided)
|-- Producer.java [Each instance of a producer generates a single number between 0 and 99 (both inclusive) randomly and inserts into the buffer, and reports the location and the time the number was inserted into the buffer] (Skeleton Code provided)
|-- Consumer.java [Each instance of a consumer reads a number from the buffer and reports the location and the time the number was read from the buffer.]
|-- Bdbuffer.java [Creates a circular buffer whose size is passed as an argument to it.]
|-- Makefile [For compiling, and cleaning]
|-- README.txt [This file]

B. - To run the program (assuming the seed is 13):

systemprompt> java Invoker 13


C. Questions:

1. The problem of producer consumer is solved using Mutex Locks. - 1 point
	a. Mutex Locks

2. What two functions defined in Java are used for synchronization between producer and consumers in your program? wait() and notify()/notifyAll(). - 2 points

3. In which function do you override the body to define the new body of a thread in java? Producer and Consumer both contain the run() method, which is the body of a thread that is overwritten. - 1 point

4. Which function is used to wait for a thread to finish and come back to calling program i.e. for a thread to die? myThread.join(). - 1 point

NOTE:

Lab systems by default use Java 11 which supports nanosecond timestamp. If after logging in and running 'java -version', it doesn't output version 11, use the following two commands:

	$ export PATH=/usr/lib/jvm/jre-11-openjdk/bin/:$PATH

	$ export LD_LIBRARY_PATH=/usr/lib/jvm/jre-11-openjdk/lib/:$LD_LIBRARY_PATH

D. Example output code:

The code below shows sample output with using 13 as the seed.

snowmass:~/cs370/hw5$ java Invoker 13
[Invoker] Buffer Size: 5
[Invoker] Total Items: 13
[Invoker] No. of Producers: 5
[Invoker] No. of Consumers: 3
Producer 1 inserted m at index 0 at time 2021-10-28 16:53:23.147501
Producer 1 inserted a at index 1 at time 2021-10-28 16:53:23.170478
Consumer 3 consumed m at index 0 at time 2021-10-28 16:53:23.170571
Consumer 3 consumed a at index 1 at time 2021-10-28 16:53:23.171142
Producer 5 inserted m at index 2 at time 2021-10-28 16:53:23.171263
Producer 5 inserted a at index 3 at time 2021-10-28 16:53:23.171358
Producer 4 inserted m at index 4 at time 2021-10-28 16:53:23.171446
Producer 4 inserted a at index 0 at time 2021-10-28 16:53:23.171537
Producer 3 inserted m at index 1 at time 2021-10-28 16:53:23.171619
Consumer 1 consumed m at index 2 at time 2021-10-28 16:53:23.171779
Consumer 1 consumed a at index 3 at time 2021-10-28 16:53:23.171858
Consumer 1 consumed m at index 4 at time 2021-10-28 16:53:23.171929
Consumer 1 consumed a at index 0 at time 2021-10-28 16:53:23.172015
Consumer 2 consumed m at index 1 at time 2021-10-28 16:53:23.172319
Producer 5 inserted j at index 2 at time 2021-10-28 16:53:23.172457
Producer 3 inserted a at index 3 at time 2021-10-28 16:53:23.172548
Producer 2 inserted m at index 4 at time 2021-10-28 16:53:23.172632
Producer 5 inserted o at index 0 at time 2021-10-28 16:53:23.172768
Producer 5 inserted r at index 1 at time 2021-10-28 16:53:23.172857
Consumer 3 consumed j at index 2 at time 2021-10-28 16:53:23.172928
Consumer 3 consumed a at index 3 at time 2021-10-28 16:53:23.173041
Consumer 3 consumed m at index 4 at time 2021-10-28 16:53:23.173107
Consumer 2 consumed o at index 0 at time 2021-10-28 16:53:23.173177
Consumer 2 consumed r at index 1 at time 2021-10-28 16:53:23.173323
Producer 2 inserted a at index 2 at time 2021-10-28 16:53:23.173444
Consumer 2 consumed a at index 2 at time 2021-10-28 16:53:23.173524
The sorted Produced and Consumed strings are the same as shown: aaaaajmmmmmor

