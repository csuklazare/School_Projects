# Sprint 2 - *t17* - *The Moist Pigeons*

## Goal
### *How far is it?*

## Scrum Master: 
### *Brock Fisher*

## Definition of Done

* The release for `v2.x` created as a GitHub Release and deployed on black-bottle under TEAM.
* The design document (`design.md`) is updated.
* The sprint document (`sprint.md`) is updated with scrums, completed metrics, review, and retrospective.

## Policies

### Mobile First Design
* Design for mobile, tablet, laptop, desktop in that order.
* Use ReactStrap for a consistent user experience (no HTML, CSS, style, etc.).

### Clean Code
* Code Climate technical debt ratio < 5.
* Minimize code smells and duplication.

### Test Driven Development
* Write the tests before writing the code.
* Tests are fully automated.

### Processes
* Main is never broken. 
* All pull request builds and tests for Main are successful.
* All dependencies managed using Maven, npm, and WebPack.
* GitHub etiquette is followed always.


## Planned Epics
For Sprint 2, the team has selected three epics to complete. These epics will add new functionality to the webapp and will improve the app's ability to work with other services. These three epics are Interoperability, Load Trip, and Distances. 

#### Interoperability

In the Interoperability epic, our team is tasked with enabling the user to use different services to plan their trip. In order to implement this, our team will implement a number of items, but they can be summed up in three main tasks. The first task will be ensuring that the client can be used with other services that have the same protocol implemented. Next, the client will also tell if the necessary features have been implemented and inform the user if they have not been. Finally, the client will be set up as to not provide/advertise any features that are not supported in its user interface. Within these three main tasks are a number of sub task that will be divided up and conquered as a team, ensuring the fastest and most efficient product in the end.

#### Load Trip

The Load Trip epic will enable the user to view previous trips in the webapp. Trips will be saved in an already existing standardized format. Trips can be loaded from an already available list of trips, from other applications that use the same format, or from trips already stored on their system. In the future they will also be able to load trips that they create themselves. This functionality will become available after the webapp is updated to save user trips. 

#### Distances

The Distance epic will add features related to distances along the user's trip. After the epic is completed users will be able to view the distances between each leg of their trip, the cumulative distance at each leg, and the total distance over the entire trip. The distance will also include the return distance from the destination to the origin. Distance will be calculated in straight lines, or as the crow flies. Finally the user will also be able to use miles, kilometers, or their own units. User-defined units will be remembered and stored locally. 

## Metrics

| Statistic | # Planned | # Completed |
| --- | ---: | ---: |
| Epics | *3* | *1* |
| Tasks |  *32*   | *34* | 
| Story Points |  *32*  | *37* | 


## Scrums

| Date | Tasks closed  | Tasks in progress | Impediments |
| :--- | :--- | :--- | :--- |
| *2/7/2022* | *#124, #132, #138* | *#126, #130, #137, #146, #148, #150* | N/A |
| *2/9/2022* | *#126, #130, #135, #137, #146, #148, #150, #195, #194, #129, #159, #177, #143, #142, #169, #197, #144, #160, #161* | N/A | N/A |
| *2/14/2022* | *#166, #171, #173, #178, #180, * | *#218, #219, #220, #182* | N/A |
| *2/16/2022* | *#216, #218, #219, #220, #224, #231, #234* | *#223, #182, #198* | Test cases, Endpoint | 
| *2/18/2022* | *#198, #223, #224, #225, #237, #238* | *#265, #268, #273* | Settings drop-down menu |
| *2/21/2022* | *#179, #181, #182, #186, #187, #188, #190, #271, #265, #260* | *#266, #247, #273* | N/A |
| *2/23/2022* | *#266, #247* | *#276, #269, #277, #278, #273* | Test cases for 'Load Trip' |


## Review

### Epics completed  

Load Trip

### Epics not completed 

Distances

Interoperability 

## Retrospective

### Things that went well

This sprint the team continued to work well with each other and spent a fair amount of time outside of 
scrum meetings / weekly meetings discussing issues while working through vode. Overall the team is 
beginning to learn the inner-workings of JS, React, and communicating across a server and client. 
Through a lot of hard work and perserverance, some of our team members were able to make breakthroughs
and then were able to share their knowledge and understanding with the rest of the team. This kind of
cooperation through difficulty will ensure our team has a good chance of working through problems
in the future. 


### Things we need to improve

Despite starting relatively early and maintaining our team's burndown chart metrics, the team was unable to 
complete 2/3rds of the epics for this sprint. In the future the team should identify and address problem 
issues early and seek outside help with them in the first week of the sprint, rather than waiting towards
the end. This sprint, the team did not properly assess which areas would be the most difficult and get
help on them early enough. We spent too much time picking off 'low-hanging fruit' in the first week
when we should have been prioritizing harder issues and tackling them early. 

### One thing we will change next time

Better identify difficult epics / tasks in the sprint and prioritize them early on, getting
help earlier rather than later. In general, just be better at staying ahead of the curve. 
