# program file:
import sys
import csv
import copy
def get_pid(list_1):
    return list_1[0]

def get_arrival_time(list_1):
    return list_1[1]

def get_priority(list_1):
    return list_1[3]

def get_empty_list_of_lists(length):
    return_list = []
    for i in range(length):
        return_list.append([])
    return return_list
        

def print_gantt_chart(curr_time, arrival_time, pid):
    print("[" + "{:^6}".format(curr_time) + "]--" + "{:^6}".format(pid) + "--[" + "{:^6}".format(arrival_time) + "]")
    return 0

def print_table(label, list_1):
    print(label)
    print("Process ID | Waiting Time | Turnaround Time")

    for x in list_1:
            print("{:^11}".format(x[0]) + "|" + "{:^14}".format(x[1]) + "|" + "{:^16}".format(x[2]))

    print()
    return 0

def schedule(label, sorted_list):
    curr_time = 0
    waiting_time = 0
    turnaround_time = 0
    list_of_lists = get_empty_list_of_lists(len(sorted_list))
    gantt_lists = []
    counter = 0
    for x in sorted_list:
        list_of_lists[counter].append(x[0])
        if curr_time < x[1]:
            gantt_lists.append([curr_time, x[1], 'IDLE'])
            curr_time = x[1]
        if curr_time > x[1]:
            gantt_lists.append([curr_time, curr_time+x[2], x[0]])
            list_of_lists[counter].append(curr_time-x[1])       # append waiting time
            list_of_lists[counter].append(curr_time-x[1]+x[2])  # append turnaround time
            waiting_time = waiting_time + (curr_time-x[1])
            turnaround_time = turnaround_time + curr_time-x[1]+x[2]
            curr_time = curr_time + x[2]
            counter = counter + 1
        else:
            gantt_lists.append([x[1], x[1]+x[2], x[0]])
            list_of_lists[counter].append(0)        # append waiting time
            list_of_lists[counter].append(x[2])     # append turnaround time
            turnaround_time = turnaround_time + x[2]
            curr_time = curr_time + x[2]
            counter = counter + 1

    sorted_pid = sorted(list_of_lists, key=get_pid, reverse=False)
    print_table(label, sorted_pid)
    print("Gantt Chart is:")
    for x in gantt_lists:
        print_gantt_chart(x[0], x[1], x[2])
    print()
    print("Average Waiting Time: " + str(waiting_time/len(sorted_list)))
    print("Average Turnaround Time: " + str(turnaround_time/len(sorted_list)))
    print("Throughput:  " + str(len(sorted_list)/curr_time))
    print('\n')

# schedule using first come first serve method
def first_come_first_serve(sorted_at):
    schedule('---------------- FCFS ----------------', sorted_at)
    return 0

# schedule using priority scheduling method
def priority_scheduling(sorted_psfinal):
    schedule('----------------- PS -----------------', sorted_psfinal)
    return 0

# schedule using round robin method
def round_robin(sorted_at, time_quantum):
    curr_time = 0
    waiting_time = 0
    turnaround_time = 0
    copy_final = copy.deepcopy(sorted_at)
    gantt_lists = []
    ready_queue = []
    unarrived_queue = copy.deepcopy(sorted_at)
    finished_queue = []

    # add all processes at arrival time 0 to ready queue and remove them from unarrived queue
    for x in sorted_at:
        if x[1] == 0:
            ready_queue.append(x)
            unarrived_queue.remove(x)

    while len(ready_queue) > 0 or len(unarrived_queue) != 0:
#        curr_process = ready_queue.pop(0)
        temp = unarrived_queue.copy()
        for x in temp:
            if x[1] <= (curr_time + time_quantum):
                ready_queue.append(x)
                unarrived_queue.remove(x)
        if len(unarrived_queue) > 0 and len(ready_queue) == 0:
            gantt_lists.append([curr_time, time_quantum + curr_time, 'IDLE'])
            curr_time = curr_time + time_quantum
            continue
        curr_process = ready_queue.pop(0)
        if curr_time < curr_process[1]:           # checks if IDLE
            gantt_lists.append([curr_time, curr_process[1], 'IDLE'])
            curr_time = curr_process[1]
                
        if curr_process[2] > time_quantum:      # if current process is not finished, add it back into the ready queue
            gantt_lists.append([curr_time, curr_time + time_quantum, curr_process[0]])
            curr_time = curr_time + time_quantum
            curr_process[2] = curr_process[2]-time_quantum
            ready_queue.append(curr_process)
        else:                                   # if current process is finished, put it in the gantt chart and add to finished queue and calculate wait and turnaround times
            gantt_lists.append([curr_time, curr_time + curr_process[2], curr_process[0]])
            curr_time = curr_time + curr_process[2]
            turnaround_time = turnaround_time + (curr_time-curr_process[1]) 
            for x in copy_final:
                if curr_process[0] == x[0]:
                    curr_process = x
            waiting_time = waiting_time + (curr_time-curr_process[2]-curr_process[1])
            finished_queue.append([curr_process[0], curr_time-curr_process[2]-curr_process[1], curr_time-curr_process[1]])

    sorted_pid = sorted(finished_queue, key=get_pid, reverse=False)
    print_table('----------------- Round Robin -----------------', sorted_pid)
    for x in gantt_lists:
        print_gantt_chart(x[0], x[1], x[2])

    print()
    print("Average Waiting Time: " + str(waiting_time/len(sorted_at)))
    print("Average Turnaround Time: " + str(turnaround_time/len(sorted_at)))
    print("Throughput:  " + str(len(sorted_at)/curr_time))
    print('\n')

    return 0

if __name__ == "__main__":

    time_quantum = int(sys.argv[2])
    # open the csv file
    with open(sys.argv[1], newline='') as csvfile:
        csv_reader = csv.reader(csvfile)
        file_1 = list(csv_reader)

    # extract column headers
    columns = file_1[0]

    # create a list of lists that have ints as values
    processes = []
    for task in file_1[1:]:
        temp = []
        for value in task:
            temp.append(int(value))

        processes.append(temp)
    # check to make sure there is at least 1 process
    if len(processes) == 0:
        print("Error: There must be at least 1 process inputted on the excel spreadsheet!")
        quit()
    
    # sort list of lists by PID
    sorted_pid = sorted(processes, key=get_pid, reverse=False)

    # sort sorted_pid by arrival time
    sorted_at = sorted(sorted_pid, key=get_arrival_time, reverse=False)

    # sort sorted_at by priority, then sort it again by arrival time
    sorted_ps = sorted(sorted_at, key=get_priority, reverse=False)
    sorted_psfinal = sorted(sorted_ps, key=get_arrival_time, reverse=False)

    # schedule tasks
    first_come_first_serve(sorted_at)
    priority_scheduling(sorted_psfinal)
    round_robin(sorted_at, time_quantum)
 
