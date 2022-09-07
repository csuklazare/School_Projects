# Inspection - Team *T17* 

The goal of an Inspection is to find defects.
We first identify the code we wish to inspect, determine the time we wish to meet, and determine the checklist we will use to find faults in our code during the preparation before the meeting.

|  | Details |
| ----- | ----- |
| Subject | *Load Trip* |
| Meeting | *3/9/2022, 7:00 pm, Teams* |
| Checklist | *https://github.com/CSU-CS-314-Spring-2022/t17/blob/main/reports/checklist.md* |

### Roles

We note the amount of time each person spent reviewing the code in preparation for the meeting.

| Name | Preparation Time |
| ---- | ---- |
| Alex | 30 minutes |
| Brock | 30 minutes |
| Hennick | 30 minutes |
| Travis | 35 minutes |
| Tony | 30 minutes |


### Problems found

We list each potential defect we found in the code during our preparation so we can discuss them in the meeting.
We add a GitHub issue for each defect that requires a modification to the system.

| file:line | problem | hi/med/low | who found | github#  |
| --- | --- | :---: | :---: | --- |
| LoadTrip:2 | Unused Import | :Low: | :Tony: | #500 |
| LoadTrip:13 | Unused Import | :Low: | :Tony: | #501 |
| LoadTrip:31 | Unused Param "distances" | :Low: | :Travis: | #502 |
| LoadTrip:70 | Unused Param "distances" | :Low: | :Tony: | #502 |
| LoadTrip:2 | Unused Import | :Low: | :Brock: | #500 |
| LoadTrip:13 | Unused Import | :Low: | :Brock: | #501 |
| LoadTrip:79 | Parsing CSV, needs to turn into JSON | :Med: | :Brock: | #448 & #449 |
| LoadTrip: 76 & 90 | Making same function call twice | :Low: | :Brock: | #506 |
| LoadTrip:77 & 91 | Making same function call twice | :Low: | :Brock: | #506 |
| LoadTrip: 70 | Unused Param "distances" | :Low: | :Brock: | #502 |
| LoadTrip: 2 | Unused Import | :Low: | :Alex: | #500 |
| LoadTrip: 13 | Unused Import | :Low: | :Alex: | #501 |
| LoadTrip: 79 & 81 | CSV Parsing fails if file contains extra data items, consider conversion to JSON | :Med: | :Alex: | #448 & #449 |
| LoadTrip:2 | Unused Import | :Low: | :Hennick: | #500 |
| LoadTrip:13 | Unused Import | :Low: | :Hennick: | #501 |
| LoadTrip:70 | Refactor loadTripInMap | :Low: | :Hennick: | #448 & #449 |

