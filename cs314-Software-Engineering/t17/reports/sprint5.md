# Sprint 5 - *t17* - *Moist Pigeons*

## Goal
### *Release!*

## Sprint Leader: 
### *Travis Schroeder*

## Definition of Done

* The Increment release for `v5.x` created as a GitHub Release and deployed on black-bottle under TEAM.
* The design document (`design.md`) is updated.
* The sprint document (`sprint.md`) is updated with scrums, completed metrics, review, and retrospective.

## Policies

### Mobile First Design
* Design for mobile, tablet, laptop, desktop in that order.
* Use ReactStrap for a consistent user experience (no HTML, CSS, style, etc.).

### Clean Code
* Code Climate technical debt ratio less than the class mean.
* Minimize code smells and duplication.

### Test Driven Development
* Code Climate technical debt ratio less than the class mean.
* Minimize code smells and duplication.
### Processes
* Incremental development.  No big bangs.
* Main is never broken. 
* All pull request builds and tests for Main are successful.
* All dependencies managed using Maven, npm, and WebPack.
* GitHub etiquette is followed always.


## Planned Epics

### Testing API

For this epic, our team is going to look back at our old code in Distances, FindPlace, and Tour, and examine why our code is failing. This will be done using postman, as well as writing our own test files and thoroughly testing our code. Once the issue is found, we will then refactor our code as necessary to make the issue disappear. This will allow us to guarantee those three elements of our page work flawlessly.

### Nearest Neighbor - 2 Opt

For this epic, it will continue off the last sprint's epic Nearest Neighbor. Our team was able to implement the Nearest Neighbor sorting algorithm last sprint, however we did not finish it by implementing the 2 optimization and 3 optimization of it. We plan on implementing 2 optimization this sprint, to give our customers the chance for a better possible returned trip than Nearest Neighbor. To do this, we will need to implement the 2 optimization algorithm, then find the "breaking point" where the optimization can't be used anymore. Once we know this, we can implement it into our code to call either 2 optimization or Nearest Neighbor when the size of the places array is below a certain threshold.

### Save Trip

For this epic, we will enable the user to save their currently loaded trip as a JSON, CSV, or SVG or KML file. This will allow the user to open their current trip into a different piece of software. The system will remember the current preferences for future sessions as well. The files are saved in the local filesystem on the computer the customer is using.

## Metrics

| Statistic | # Planned | # Completed |
| --- | ---: | ---: |
| Epics | *3* | *2* |
| Tasks |  *12*   | *69* | 
| Story Points |  *14*  | *66* | 


## Scrums

| Date | Tasks closed  | Tasks in progress | Impediments |
| :--- | :--- | :--- | :--- |
| *4/18* | *#717, #728, #727, #719, #716, #732* | *#762, #750, #747, #738* | *n/a* |
| *4/20* | *#749, #750, #755, #768, #738, #762, #764, #767, #752, #747* | *#739, #740, #741* | *n/a* | 
| *4/22* | *n/a* | *#739, #740, #741, #772, #758, #745, #746* | *n/a* | 
| *4/25* | *#743, #758, #746, #744, #742, #745, #785, #777, #786* | *#744, #739, #740, #741* | *figure out postman issues with TA*|
| *4/27* | *#788, #790, #745, #746, #804, #806, #798, #796, #795, #794, #800* | *#601, #807* | *Help with Postman from team* |
| *4/29* | *#814, #813, #818, #812, #825, #807, #800* | *#831, #847, #850, #832* | *n/a* |
| *5/2*  | *#832, #850, #831, #836, #847 #850* | *#857, #859, #864 #865 #868 #870 #878, #879* | *n/a* |
| *5/4*  | *#878, #879, #880, #870, #868, #865, #864, #862, #859, #857, #854, #841* | *#844, #883, #881, #879, #887, #851* | *n/a* |



## Review

### Epics completed  
- Save Trip
- Testing API

### Epics not completed 
- Nearest Neighbor 2 opt and 3 opt
- Save Trip SVG & KML File Types

## Retrospective

### Things that went well

At the beginning of the sprint, the team did not prioritize planning very well. This led to not very many story points and tasks being created. However, the team came together over the course of the sprint, created tasks as we went along, and was able to still complete 2 epics by the end of the sprint, as well as refactor and fix a lot of the code. This was well done by the team, as we were able to make up for our lack of concrete planning at the beginning of the sprint. Another thing that went well this sprint was everyone did their part to help out. Work loads were only slightly skewed, and everyone on the team contributed a lot of effort to finalize our software before the final release.

### Things we need to improve

At the beginning of the sprint, our team was slightly more lax on the plan for this Sprint, and it was reflected in our grade. This is something we need to prioritize at the beginning as it will help expedite the process and keep the team focused the rest of the sprint. Another item we can improve on is to fix code before we write any more code in the certain file. At the end of this sprint, our team was tasked with going through and refactoring lots of the code. This process had double ups, and could have been minimized if we were to fix code before we wrote more code in the file.

### One thing we will change next time

As we did in previous sprints, prioritize planning the sprint out better at the start, to avoid having to add in so many tasks and story points during the sprint. This will allow the final goal of the sprint to be more easily obtainable.
