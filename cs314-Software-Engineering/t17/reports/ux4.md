# User Experience - Team *T17* 

The report summarizes user experience testing performed on the team's application.

Each developer should ask the user to accomplish one or more simple tasks while monitoring their efforts.  
The user should attempt to complete the tasks without any aid from the developer.
Use a pseudonym to identify the user below. 
Set a time limit and tasks for the user to perform.

 
### Tasks

Each user should complete the following tasks in 10 minutes.
Developers should not guide the user, but the user may ask for help as a last resort.  
Consider this a failure when it happens.  

1. Upload a valid JSON file for a trip.
2. Add 10 places by clicking on the map.
3. Add 5 places by searching the database for a specific name.
4. Add 5 places by searching for exact coordinates.
5. Attempt to connect to 2 different team's servers.
6. After adding all of these places, remove 5 places manually at random.
7. Use the remove all button to reset the map back to 0 places.

### Demographics

Age, nationality, and other background information can sometimes be helpful understanding the problems a user encountered.

| Pseudonym | Demographics |
| :--- | :--- |
| fisher25Sums | 25, American, Ethnicity = White/Colombian, Familar with Computers |
| fisher25Brady | 28, American, Ethnicity = White, Very familiar with Computers |
| fisher25Mana | 24, American, Ethnicity = White, Familiar with Computers |
| MissKnowItAll | 32, American, Ethnicity = White, Familiar with Computers |
| amwaddleA | 22, American, Ethnicity = White, Familiar with Computers | 
| amwaddleS | 30, American, Ethnicity = White, Familiar with Computers | 
| Atechnician | 22, American, White, Fammiliar with Computers |
| Rubin Perez | 21, American, White/Asian, Familiar with Computers |


### Observations

Note the users interactions with the system for each of the tasks.
Record the success, failures, and problems the user encountered for each task.
Note any aid that was given along with anything you notice from their use of the application.
Add issues to GitHub for any changes necessary to the system.

| Pseudonym | Task | problem, aid, observation | hi/med/low | github#  |
| :--- | :--- | :---: | :---: | :---: |
| fisher25Brady | 4 | Didn't know max coordinate values for Lat & Lng, Had to google them | Low | To increase user friendliness, add max and min limits issue #657| 
| fisher25Sums | 5 | Couldn't figure out how to connect to team server, Had to give her hint it was at bottom of page | Low | To increase user friendliness, add an official "change server" button issue #656 |
| Atechnician | 2 | Settings menu wasn't clear. The 3 vertical dots holding options (upload, find, etc) wasn't obvious and they recommend having the options plainly visible. | Low | To increase user friendliness, add trip options to the default page (if viewport is large enough) #662|
| Rubin Perez | 4 | The add place button for adding a place by coordinates is placed in the footer, hard for the user to see | Med | Change location of add place button to next to coord input string, #693 |
| Rubin Perez | 5 | User could not figure out where the change server button was, or what other team's server ports where | Low | add an explicit "change server button", maybe add list of other available server ports, #656 |
| amwaddleS | 5 | Was not able to find the option to connect to another team's server. She thought the 'http://localhost:8000' button was a link to a different page. | Low | Create clearly-marked button for changing the connected server (Issue already opened #656) |
| amwaddleA | 6 | Did not run into any issues but suggested changing the three-dot settings on each location to a remove/trash icon because there are not any other options when clicked. | Low | Consider swapping out three-dot icon to the right of each location with a trash/removal icon #665 |
| zypher | 4 | Caused a crash by adding an Unknown Place | High | Investigate potential bugs with adding unknown places. #678 |
| zypher | 5 | Did not know team numbers or how to connect to them | Low | Consider adding a list of team ports in the connect popup.  |

