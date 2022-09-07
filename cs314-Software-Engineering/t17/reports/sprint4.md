# Sprint 4 - *t17* - *The Moist Pidgeons*

## Goal
### *Shorter tours!*

## Sprint Leader: 
### *Hennick Yibra*

## Definition of Done

* The Increment release for `v4.x` created as a GitHub Release and deployed on black-bottle under SPRINT.
* The design document (`design.md`) is updated.
* The sprint document (`sprint.md`) is updated with scrums, completed metrics, review, and retrospective.

## Policies

### Mobile First Design
* Design for mobile, tablet, laptop, desktop in that order.
* Use ReactStrap for a consistent user experience (no HTML, CSS, style, etc.).

### Clean Code
* Code Climate maintainability of A (technical debt ratio==0).
* Minimize code smells and duplication.
* Use Single Responsibility Principle.

### Test Driven Development
* Write the tests before the code.
* Unit tests are fully automated.
* Code coverage is 70%

### Processes
* Incremental development.  No big bangs.
* Main is never broken. 
* All pull request builds and tests for Main are successful.
* All dependencies managed using Maven, npm, and WebPack.
* GitHub etiquette is followed always.


## Planned Epics

### Tour Client Side

For this epic we will be creating an additional menu that will allow the user to optimize their trip by distance. This menu will provide the user with the option of optimizing their trip using the server-side algorithms to minimize the total distance of the trip by re-sorting the trip by nearest locations. The menu will provide a graphical view of these sorted locations and allow the user to choose whether or not they would like the original trip to be updated. If the user decides to update the trip, the newly sorted trip will be updated in the main view.

### Tour Server Side
For this epic we will create a tour response object in response to the client's tour request. First, the incoming request will be validated with the tourRequest.json schema. We'll create a tourResponse class that builds the response once the request is validated. This class will return the same list papssed in the request body, if the 'response' attribute is 0. Otherwise, it will use the nearest neighbor algorithm imported from another class to optimize the trip.

### Nearest Neighbor
For this epic, we will use an algorithm called "Nearest Neighbor" that will allow us to calculate a shorter round trip from the user's specified trip. This epic will be 3 main parts, with the first part implementing the basic optimization of Nearest Neighbor. As the epic progresses, we will create a 2 way optimization and 3 way optimization to further optimize how short the trip's round trip distance will be. A key part to this epic will be finding the breaking points of each of the optimizations, and knowing which optimization to use where. We will focus first on getting the basic optimization completed before we continue onto further optimization.

### Find By Place: Server Side
This epic was carried over from last sprint. Unfortunately, we were unable to complete it last sprint. However, for this sprint, this epic is small. The only item left is to change the query to poll the entire database as we are only polling 3 or 4 of the tables now. Once this is completed, we can close this epic.


## Metrics

| Statistic | # Planned | # Completed |
| --- | ---: | ---: |
| Epics | 3 | 8 |
| Tasks |  19   | 56 | 
| Story Points |  23  | 47 | 


## Scrums

| Date | Tasks closed  | Tasks in progress | Impediments |
| :--- | :--- | :--- | :--- |
| *3/28* | *#565, #566, #567, #568, #570, #571, #572* | *N/A* | N/A | 
| *3/30* | *#609, #617, #619* | *N/A* | N/A |
| *4/01* | *#627, #633, #592, #595, #596, #597, #598, #599, #608, #629* | *#681, #553* | N/A |
| *4/04* | *#647, #648, #650, #649, #411, #639, #644, #641, #642, #634* | *#652, #651, #681, #682* | N/A |
| *4/08* | *#689, #695, #667, #692, #685, #686, #687, #699, #700* | *#697, #702* | N/A |
| *4/10* | *#711, #703* | *#702* | N/A |
| *4/11* | *#705* | *#714* | N/A |
| *4/13* | *#714, #697, #702, #600* | *#716, #717, #719, #723, #724, #725, #727, #728* | N/A |


## Review

### Epics completed  

- Tour Client Side
- Tour Server Side
- Find By Place: Server Side
- Nearest Neighbor base algorithm

### Epics not completed 
- Nearest Neighbor 2-optimization and 3-optimization

## Retrospective

### Things that went well
- Our team was able to divide up tasks much more efficiently this time around, which allowed the group to complete almost all of the epics this Sprint. We did not complete our nearest neighbor epic completely, as that involves implementing 2-way optimization and 3-way optimization, but we did complete the base part of the epic. Other things that went well was the team sought help earlier and more often when stuck on something, allowing us to progress quicker as a team.

### Things we need to improve
- One thing we need to improve on is deciding earlier when we cannot complete an epic. This will allow us to divide tasks up more evenly, and focus on the more important tasks towards the end of the sprint. Another thing we could work on is implementing a better code review. We missed points on it this sprint. As a team, we need to go over the code more in depth before the meeting, so we can have a more thoughtful meeting.

### One thing we will change next time
- One thing the team will change for next time is to allocate more time to going through old code to make sure that it is running properly without bugs. Not just for the inpsection report, but as a whole.
