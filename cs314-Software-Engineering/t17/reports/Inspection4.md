# Inspection - Team *T17* 

The goal of an Inspection is to find defects.
We first identify the code we wish to inspect, determine the time we wish to meet, and determine the checklist we will use to find faults in our code during the preparation before the meeting.

|  | Details |
| ----- | ----- |
| Subject | *AddPlace* |
| Meeting | *4/7/2022, 3:00 pm, Teams* |
| Checklist | *https://github.com/CSU-CS-314-Spring-2022/t17/blob/main/reports/checklist.md* |

### Roles

We note the amount of time each person spent reviewing the code in preparation for the meeting.

| Name | Preparation Time |
| ---- | ---- |
| Alex | 20 minutes |
| Brock |  |
| Hennick | 15 minutes |
| Travis | 30 minutes |
| Tony | 30 minutes |


### Problems found

We list each potential defect we found in the code during our preparation so we can discuss them in the meeting.
We add a GitHub issue for each defect that requires a modification to the system.

| file:line | problem | hi/med/low | who found | github#  |
| --- | --- | :---: | :---: | --- |
| AddPlace:62 | Unclear what this code snip is doing | low | Tony | N/A |
| AddPlace:54 | Function: PlaceSearch does not verify inputs, could lead to crash | low | Tony | N/A |
| AddPlace:95 | Function: PlaceInfo does not verify inputs, could lead to crash | low | Tony | N/A |
| AddPlace:103 | Function: FoundPlacesInfo: does not verify inputs, could lead to crash | low | Tony | N/A |
| AddPlace:23 | setNameString() is set to null on close, could lead to null pointers | low| Brock | #686 |
| AddPlace: 68 | Function: PlaceSearch does not verify inputs, could crash if invalid | low | Brock | N/A |
| AddPlace: 62 | Function: PlaceSearch toggle in line 62 is never used, could delete line | low | Brock | #687 |
| AddPlace: 62 | 'toggle' is never used | low | Hennick | #687 |
| AddPlace: 62 | Toggle function is declared but never used, consider removing | low | Alex | #687 |
| AddPlace:137 | Move 'add place' button from footer to next to coordinate search box | med | Travis | #693 |

