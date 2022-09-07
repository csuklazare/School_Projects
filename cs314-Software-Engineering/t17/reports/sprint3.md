# Sprint 3 - *t17* - *The Moist Pigeons*

## Goal
### *Where should we go?*

## Sprint Leader: 
### *Alex Waddle*

## Definition of Done

* The Increment release for `v3.x` created as a GitHub Release and deployed on black-bottle under TEAM.
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
* Write the tests before the code.
* Unit tests are fully automated.
* Code coverage is greater than the class mean.

### Processes
* Incremental development.  No big bangs.
* Main is never broken. 
* All pull request builds and tests for Main are successful.
* All dependencies managed using Maven, npm, and WebPack.
* GitHub etiquette is followed always.


## Planned Epics

**Distances**
  In order to finish the Distances Epic off, we are needing to implement distances to work with the Add Trip function of the web page. Currently, distances are only loaded in off of a JSON file. In order to do this, we will need to create a new API request function that requests the distance everytime Add Trip is called. With this, this should give the user the ability to see the cumulative distance at each stop along the way of their manually added trip.

**Find Place**
  This is an overarching Super Epic that will be broken into smaller, more manageable Epics. There will be a total of 8 Epics for this overarching Epic. These are listed below:

* **Find by Place: Client**
  We will provide a 'find' feature for the user. The user will be able to make a 'find request', providing a string 'match' that will be used by the server to return a response containing a list of all places 'matching' the specified string pattern. This epic will also contain a limit property which specifies the upper limit of locations that the server can include in the response.

* **Find by Type: Client**
  This epic will build off the Find by Place epic. Once we have the capability of finding a place, we will allow the user to add in a filter by "type". The types are airports, heliports, ship ports, etc. To do this, we will add a drop down menu with specific types. We will also need to create a request for type of place from the database. Once the response from the server has been received, a popup window will contain all of the relevant places that are returned from the server.
  
* **Find Place: Random Generated List: Client**
  This epic will build off the Find by Place epic. This epic will consist of allowing the user to not specify anything in the match property. If nothing is specified in the match property, our web page will return a random list of places throughout the world that still hold the other properties passed to the web page. We will limit the random places to 10 for now, but can add more if needed as the project develops. For the client side, there won't be too much to do. The client will need to watch for the match property not being specified. If it isn't specified, it will call the server with a request of 10 random places. Once these are returned, they will be displayed in a pop up window.

* **Find by Country: Client**
  We will create a radio button 'Find by Country' which the user can select to be given an option to input countries they'd like their find request to be restricted to. 'Find by country' will not be considered an attribute if the user gives no input after selecting the option.

* **Find by Place: Server**
  The server will return a list of locations matching the string provided by the user. To do this the server will need to establish a connection to an SQL database and query the database to find locations matching said string, bounded by the 'limit' property. Afterwards, the data will be recorded and formatted prior to buildResponse.

* **Find by Type: Server**
 In this epic, we will mainly focus on completing the server side of the epic. Once the request from the client has been received and verified by the server, the server will search the database for all places that match the given type parameter. The server will create a response, and return this response to the client.

* **Find by Country: Server**
    The server will take the 'Find by Country' input as a parameter to be considered when querying the database. This paramenter will restrict the database query to only places contained within the users request, thereby modifying the response.

* **Add Found Place**
  This epic will give the user the ability to add a place found by their search, to their trip. There will be a button in the 'Find Places' window that the user can click to add the place(s) returned by their search.
  We will need to create a database response that will contain the information of the matches and use that to display these places to the user.

* **Find Place: Random Generated List: Server**
  This epic will focus on the server side of generating a random list. Once the request to the server has been received, the server will pull the database for 10 random places that meet the specified parameters. Once these 10 places have been found, the server will construct them in an array, and send them back to the client.

**Load Trip With CSV File**
  To complete the Load Trip Epic from Sprint 2, our team needs to nail down the CSV file input. Currently, our webpage allows the uploading of JSON files, and basic CSV files. If the CSV files have any "extra" information though, our webpage does not work. To complete this Epic, we will need to figure out exactly how we are parsing the CSV file, then see where our bug is being created. Once we have that information, we will be able to edit our code and allow the CSV files to be uploaded successfully.

**Interoperability**
  Our team was unable to get to this Epic last Sprint. Our hopes are to implement this Epic at the end of the Sprint. To complete this epic this sprint, we need to check if each server we are connecting to has the same protocols implemented as our client. If this doesn't match up, we will have a pop up box/error thrown stating just that.


## Metrics

| Statistic | # Planned | # Completed |
| --- | ---: | ---: |
| Epics | 15 | *4* |
| Tasks |  57   | *81* | 
| Story Points |  57  | *66* | 


## Scrums

| Date | Tasks closed  | Tasks in progress | Impediments |
| :--- | :--- | :--- | :--- |
| *3/2/2022* | *#336, #338, #343, #349, #351, #353, #354, #357, #361, #384, #388, #389, #365, #372, #373, #376, #377, #380, #429, #434, #455* | *#464, #466, #467, #468, #472* | N/A | 
| *3/4/2022* | *#464, #466, #467, #468, #472* | *#400, #465* | N/A | 
| *3/7/2022* | *#400, #465* | *#332, #333, #392* | N/A |
| *3/8/2022* | *#332, #333, #392* | *#403, #406, #410, #486, #340* | Distances test case |
| *3/9/2022* | *#486, #340* | *#410, #490, #500, #501, #502* | Accessing database through Java/JS | 
| *3/11/2022* | *#490, #500, #501, #502* | *#410* | N/A | 
| *3/21/2022* | *#515, #516, #519, #522, #524, #526, #529, #531* | *#539, #534, #533, #543, #535* | Increasing test coverage | 
| *3/23/2022* | *#533, #534, #535, #543* | *#544, #545* | Writing client-side tests | 


## Review

### Epics completed  
- Distances
- Find by Place: Client
- Find by Place: Server
- Add Found Place

### Epics not completed 
- Find Place - The overarching Find Place Epic was not completed, but parts of it were.
- Find by Type: Client
- Find Place: Random Generated List
- Find by Country: Client
- Find by Type: Server
- Find by Country: Server
- Find Place: Random Generated List: Server
- Load Trip With CSV File
- Interoperability

## Retrospective

### Things that went well

  At the beginning of the Sprint, one thing the team successfully completed was breaking down the larger Epics into smaller Epics. This allowed the team to really delve into each of these Epics and break them down even further into more manageable tasks. Doing this allowed the team to begin on the Epics earlier than the previous Sprint. Another thing the team did well this Epic was help each other out when they were stuck. This allowed the team to complete some of the bigger Epics by saving time with helping each other out.

### Things we need to improve

  The biggest issue the team ran into this Sprint was dividing up the workload earlier to teammates to allow the team to complete more Epics. The team was able to complete only 1/3 of the scheduled Epics that were planned. However, some of the Epics that were completed were bigger Epics, and quite a few of the Epics that weren't completed were smaller Epics that tie into the bigger Epics. With this said, the team needs to divide work up earlier in the Sprint to allow more work to be accomplished in a timely manner so more Epics can be completed.

### One thing we will change next time
  
  One thing the team will change for next time is to assign tasks early to team members and expect team members to complete this work in a timely manner so the team can progress quicker.
